#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include <atomic>
//#include <fstream>

#include <verilated.h>
#include "Vtop.h"


#include "../imgui/imgui.h"
#ifndef WINDOWS
#include "../imgui/imgui_impl_sdl.h"
#include "../imgui/imgui_impl_opengl2.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>

#else
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#endif

#include "../imgui/imgui_memory_editor.h"

FILE *ioctl_file=NULL;
FILE *ioctl_upload_file=NULL;
int ioctl_next_addr = 0x0;

#ifndef WINDOWS
SDL_Renderer * renderer =NULL;
SDL_Texture * texture =NULL;
#else
// DirectX data
static ID3D11Device*            g_pd3dDevice = NULL;
static ID3D11DeviceContext*     g_pd3dDeviceContext = NULL;
static IDXGIFactory*            g_pFactory = NULL;
static ID3D11Buffer*            g_pVB = NULL;
static ID3D11Buffer*            g_pIB = NULL;
static ID3D10Blob*              g_pVertexShaderBlob = NULL;
static ID3D11VertexShader*      g_pVertexShader = NULL;
static ID3D11InputLayout*       g_pInputLayout = NULL;
static ID3D11Buffer*            g_pVertexConstantBuffer = NULL;
static ID3D10Blob*              g_pPixelShaderBlob = NULL;
static ID3D11PixelShader*       g_pPixelShader = NULL;
static ID3D11SamplerState*      g_pFontSampler = NULL;
static ID3D11ShaderResourceView*g_pFontTextureView = NULL;
static ID3D11RasterizerState*   g_pRasterizerState = NULL;
static ID3D11BlendState*        g_pBlendState = NULL;
static ID3D11DepthStencilState* g_pDepthStencilState = NULL;
static int                      g_VertexBufferSize = 5000, g_IndexBufferSize = 10000;
#endif


// Instantiation of module.
Vtop* top = NULL;

char my_string[1024];
int str_i = 0;

unsigned int file_size;

unsigned int row;
unsigned int col;
unsigned int bank;
unsigned int dram_address;

int pix_count = 0;

unsigned char rgb[3];
bool prev_vsync = 0;
int frame_count = 0;

bool vga_file_select = 0;

bool prev_hsync = 0;
int line_count = 0;

bool prev_sram_we_n = 0;

uint32_t inst_data_temp;

uint32_t prev_pc = 0xDEADBEEF;

unsigned int avm_byte_addr;
unsigned int avm_word_addr;

unsigned int burstcount;
unsigned int byteenable;
unsigned int writedata;

unsigned int datamux;	// What the aoR3000 core is actually reading from the bus! Only valid when avm_readdata_valid is High!
unsigned int datatemp;

unsigned int old_pc;
unsigned int inst_count = 0;

unsigned int old_hw_addr;
unsigned int hw_count = 0;

bool trigger1 = 0;
bool trigger2 = 0;

int trig_count = 0;

uint16_t byteena_bits;

bool ram_read_flag = 0;
bool ram_write_flag = 0;

FILE *vgap;

int last_sdram_writedata = 0;
int last_sdram_byteaddr = 0;
int last_sdram_ben = 0;

bool run_enable = 0;
bool single_step = 0;
bool multi_step = 0;
int multi_step_amount = 1024;

void ioctl_download_before_eval(void);
void ioctl_download_after_eval(void);
void ioctl_upload_before_eval(void);
void ioctl_upload_after_eval(void);

#ifdef WINDOWS
// Data
static IDXGISwapChain*          g_pSwapChain = NULL;
static ID3D11RenderTargetView*  g_mainRenderTargetView = NULL;

void CreateRenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
	pBackBuffer->Release();
}

void CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

HRESULT CreateDeviceD3D(HWND hWnd)
{
	// Setup swap chain
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
		return E_FAIL;

	CreateRenderTarget();

	return S_OK;
}

void CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
#else
#endif


static float values[90] = { 0 };
static int values_offset = 0;


uint64_t main_time = 0;	// Current simulation time.

unsigned char buffer[16];

unsigned int ram_size = 32768;	    //32KB (8-bit wide).	
uint32_t *ram_ptr = (uint32_t *) malloc(ram_size);

#define BUF_WIDTH 1024
#define BUF_HEIGHT 1024
#define VGA_WIDTH 640
#define VGA_HEIGHT 480

unsigned int disp_size = BUF_WIDTH * BUF_HEIGHT * 4;
uint32_t *disp_ptr = (uint32_t *)malloc(disp_size);


double sc_time_stamp () {	// Called by $time in Verilog.
	return main_time;
}


ImVector<char*>       Items;
static char* Strdup(const char *str) { size_t len = strlen(str) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)str, len); }

// Demonstrate creating a simple console window, with scrolling, filtering, completion and history.
// For the console example, here we are using a more C++ like approach of declaring a class to hold the data and the functions.
struct ExampleAppConsole
{
	char                  InputBuf[256];
	ImVector<const char*> Commands;
	ImVector<char*>       History;
	int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
	ImGuiTextFilter       Filter;
	bool                  AutoScroll;
	bool                  ScrollToBottom;
void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
{
	// FIXME-OPT
	char buf[1024];
	va_list args;
	va_start(args, fmt);
	vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
	buf[IM_ARRAYSIZE(buf) - 1] = 0;
	va_end(args);
	Items.push_back(Strdup(buf));
}
	ExampleAppConsole()
	{
		ClearLog();
		memset(InputBuf, 0, sizeof(InputBuf));
		HistoryPos = -1;
		Commands.push_back("HELP");
		Commands.push_back("HISTORY");
		Commands.push_back("CLEAR");
		AutoScroll = true;
		ScrollToBottom = false;
		AddLog("Gigatron Core Sim start");
		AddLog("");
	}
	~ExampleAppConsole()
	{
		ClearLog();
		for (int i = 0; i < History.Size; i++)
			free(History[i]);
	}

	// Portable helpers
	//static int   Stricmp(const char* str1, const char* str2) { int d; while ((d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; } return d; }
	//static int   Strnicmp(const char* str1, const char* str2, int n) { int d = 0; while (n > 0 && (d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; n--; } return d; }
//	static char* Strdup(const char *str) { size_t len = strlen(str) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)str, len); }
	//static void  Strtrim(char* str) { char* str_end = str + strlen(str); while (str_end > str && str_end[-1] == ' ') str_end--; *str_end = 0; }

	void    ClearLog()
	{
		for (int i = 0; i < Items.Size; i++)
			free(Items[i]);
		Items.clear();
	}

	void    Draw(const char* title, bool* p_open)
	{
		//ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
		//if (!ImGui::Begin(title, p_open))
		//{
			//ImGui::End();
			//return;
		//}

		//// As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar. So e.g. IsItemHovered() will return true when hovering the title bar.
		//// Here we create a context menu only available from the title bar.
		//if (ImGui::BeginPopupContextItem())
		//{
			//if (ImGui::MenuItem("Close Console"))
				//*p_open = false;
			//ImGui::EndPopup();
		//}

		//if (ImGui::SmallButton("Clear")) { ClearLog(); } ImGui::SameLine();
		//bool copy_to_clipboard = ImGui::SmallButton("Copy");

		//ImGui::Separator();

		//// Options menu
		//if (ImGui::BeginPopup("Options"))
		//{
			//ImGui::Checkbox("Auto-scroll", &AutoScroll);
			//ImGui::EndPopup();
		//}

		//// Options, Filter
		//if (ImGui::Button("Options"))
			//ImGui::OpenPopup("Options");
		//ImGui::SameLine();
		//Filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
		//ImGui::Separator();

		//const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
		//ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText
		//if (ImGui::BeginPopupContextWindow())
		//{
			//if (ImGui::Selectable("Clear")) ClearLog();
			//ImGui::EndPopup();
		//}

		//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
		//if (copy_to_clipboard)
			//ImGui::LogToClipboard();
		//for (int i = 0; i < Items.Size; i++)
		//{
			//const char* item = Items[i];
			//if (!Filter.PassFilter(item))
				//continue;

			//// Normally you would store more information in your item (e.g. make Items[] an array of structure, store color/type etc.)
			//bool pop_color = false;
			////if (strstr(item, "[error]")) { ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f)); pop_color = true; }
			////else if (strncmp(item, "# ", 2) == 0) { ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.8f, 0.6f, 1.0f)); pop_color = true; }
			//ImGui::TextUnformatted(item);
			//if (pop_color)
				//ImGui::PopStyleColor();
		//}
		//if (copy_to_clipboard)
			//ImGui::LogFinish();

		//if (ScrollToBottom || (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
			//ImGui::SetScrollHereY(1.0f);
		//ScrollToBottom = false;

		//ImGui::PopStyleVar();
		//ImGui::EndChild();
		//ImGui::Separator();

		//// Command-line
		//bool reclaim_focus = false;
		//if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory, &TextEditCallbackStub, (void*)this))
		//{
			//char* s = InputBuf;
			//Strtrim(s);
			//if (s[0])
				//ExecCommand(s);
			//strcpy(s, "");
			//reclaim_focus = true;
		//}

		//// Auto-focus on window apparition
		//ImGui::SetItemDefaultFocus();
		//if (reclaim_focus)
			//ImGui::SetKeyboardFocusHere(-1); // Auto focus previous widget

		//ImGui::End();
	}

	void    ExecCommand(const char* command_line)
	{
		//AddLog("# %s\n", command_line);

		//// Insert into history. First find match and delete it so it can be pushed to the back. This isn't trying to be smart or optimal.
		//HistoryPos = -1;
		//for (int i = History.Size - 1; i >= 0; i--)
			//if (Stricmp(History[i], command_line) == 0)
			//{
				//free(History[i]);
				//History.erase(History.begin() + i);
				//break;
			//}
		//History.push_back(Strdup(command_line));

		//// Process command
		//if (Stricmp(command_line, "CLEAR") == 0)
		//{
			//ClearLog();
		//}
		//else if (Stricmp(command_line, "HELP") == 0)
		//{
			//this->AddLog("Commands:");
			//for (int i = 0; i < Commands.Size; i++)
				//this->AddLog("- %s", Commands[i]);
		//}
		//else if (Stricmp(command_line, "HISTORY") == 0)
		//{
			//int first = History.Size - 10;
			//for (int i = first > 0 ? first : 0; i < History.Size; i++)
				//this->AddLog("%3d: %s\n", i, History[i]);
		//}
		//else
		//{
			//this->AddLog("Unknown command: '%s'\n", command_line);
		//}

		//// On commad input, we scroll to bottom even if AutoScroll==false
		//ScrollToBottom = true;
	//}

	//static int TextEditCallbackStub(ImGuiInputTextCallbackData* data) // In C++11 you are better off using lambdas for this sort of forwarding callbacks
	//{
		//ExampleAppConsole* console = (ExampleAppConsole*)data->UserData;
		//return console->TextEditCallback(data);
	//}

	//int     TextEditCallback(ImGuiInputTextCallbackData* data)
	//{
		////AddLog("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);
		//switch (data->EventFlag)
		//{
		//case ImGuiInputTextFlags_CallbackCompletion:
		//{
			//// Example of TEXT COMPLETION

			//// Locate beginning of current word
			//const char* word_end = data->Buf + data->CursorPos;
			//const char* word_start = word_end;
			//while (word_start > data->Buf)
			//{
				//const char c = word_start[-1];
				//if (c == ' ' || c == '\t' || c == ',' || c == ';')
					//break;
				//word_start--;
			//}

			//// Build a list of candidates
			//ImVector<const char*> candidates;
			//for (int i = 0; i < Commands.Size; i++)
				//if (Strnicmp(Commands[i], word_start, (int)(word_end - word_start)) == 0)
					//candidates.push_back(Commands[i]);

			//if (candidates.Size == 0)
			//{
				//// No match
				//this->AddLog("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
			//}
			//else if (candidates.Size == 1)
			//{
				//// Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
				//data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
				//data->InsertChars(data->CursorPos, candidates[0]);
				//data->InsertChars(data->CursorPos, " ");
			//}
			//else
			//{
				//// Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
				//int match_len = (int)(word_end - word_start);
				//for (;;)
				//{
					//int c = 0;
					//bool all_candidates_matches = true;
					//for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
						//if (i == 0)
							//c = toupper(candidates[i][match_len]);
						//else if (c == 0 || c != toupper(candidates[i][match_len]))
							//all_candidates_matches = false;
					//if (!all_candidates_matches)
						//break;
					//match_len++;
				//}

				//if (match_len > 0)
				//{
					//data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
					//data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
				//}

				//// List matches
				//this->AddLog("Possible matches:\n");
				//for (int i = 0; i < candidates.Size; i++)
					//this->AddLog("- %s\n", candidates[i]);
			//}

			//break;
		//}
		//case ImGuiInputTextFlags_CallbackHistory:
		//{
			//// Example of HISTORY
			//const int prev_history_pos = HistoryPos;
			//if (data->EventKey == ImGuiKey_UpArrow)
			//{
				//if (HistoryPos == -1)
					//HistoryPos = History.Size - 1;
				//else if (HistoryPos > 0)
					//HistoryPos--;
			//}
			//else if (data->EventKey == ImGuiKey_DownArrow)
			//{
				//if (HistoryPos != -1)
					//if (++HistoryPos >= History.Size)
						//HistoryPos = -1;
			//}

			//// A better implementation would preserve the data on the current input line along with cursor position.
			//if (prev_history_pos != HistoryPos)
			//{
				//const char* history_str = (HistoryPos >= 0) ? History[HistoryPos] : "";
				//data->DeleteChars(0, data->BufTextLen);
				//data->InsertChars(0, history_str);
			//}
		//}
		//}
		//return 0;
	}
};

static ExampleAppConsole console;

static void ShowExampleAppConsole(bool* p_open)
{
	console.Draw("Debug Log", p_open);
}



int verilate() {
	if (!Verilated::gotFinish()) {
		if (main_time < 2048) {
			top->reset = 1;   	// Assert reset (active HIGH)
		}
		if (main_time == 2048) {	// Do == here, so we can still reset it in the main loop.
			top->reset = 0;		// Deassert reset.
		}
		top->clk_sys=!top->clk_sys;
		if (main_time%2==0) {
		    top->clk_vid=!top->clk_vid;
		}
        if (main_time%8==0) {
		    top->clk_app=!top->clk_app;
		}
		if (top->clk_vid && !top->reset) {
		    if (frame_count > 2) {
                pix_count++;

                rgb[0] = top->VGA_B;
                rgb[1] = top->VGA_G;
                rgb[2] = top->VGA_R;
                uint32_t vga_addr = line_count * VGA_WIDTH + pix_count;
                //uint32_t vga_addr = ((1024-pix_count) * 1024) +line_count;
                disp_ptr[vga_addr] = 0xFF000000 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];	// Our debugger framebuffer is in the 32-bit RGBA format.
            }

            if (prev_hsync && !top->VGA_HS) {
				line_count++;
				pix_count = 0;
            }
            prev_hsync = top->VGA_HS;
			
            if (prev_vsync && !top->VGA_VS) {
                frame_count++;
                line_count = 0;
                pix_count = 0;
                //sprintf(my_string, "Frame: %06d  VSync! ", frame_count);
                printf("Frame: %06d  VSync!\n", frame_count);
                //console.AddLog(my_string);
            }
            prev_vsync = top->VGA_VS;
        }
#if 1
        if (top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__wren) {
            ram_ptr[top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__address] = top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__data;
                //printf("Wrote %x to %x\n", top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__data, top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__address);
        }
#endif

        if (top->clk_sys) {
            ioctl_upload_before_eval();
            ioctl_download_before_eval();
        }
        else if (ioctl_file)
            printf("skipping download this cycle %d\n",top->clk_sys);

        top->eval();            // Evaluate model!

        if (top->clk_sys) {
            ioctl_upload_after_eval();
            ioctl_download_after_eval();
        }

        main_time++;            // Time passes...

		return 1;
	}
	// Stop Verilating...
	top->final();
	delete top;
	exit(0);
	return 0;
}

int ioctl_upload_size = 0;
void ioctl_upload_setfile(char *file, int index,int size)
{
    ioctl_upload_size = size;
    ioctl_next_addr = -1;
    top->ioctl_addr=ioctl_next_addr;
    top->ioctl_index = index;
    ioctl_upload_file=fopen(file,"wb");
    if (!ioctl_upload_file) printf("error opening %s\n",file);
}
void ioctl_upload_before_eval()
{
    if (ioctl_upload_file) {
printf("ioctl_upload_before_eval %x\n",top->ioctl_addr);
        if (top->ioctl_wait==0) {
        top->ioctl_upload=1;
        top->ioctl_wr = 1;
    
        if (ioctl_next_addr > ioctl_upload_size) {
            fclose(ioctl_upload_file);
            ioctl_upload_file=NULL;
            top->ioctl_upload=0;
                top->ioctl_wr = 0;
           printf("finished upload\n");

        }
            if (ioctl_upload_file) {
                fputc(top->ioctl_din,ioctl_upload_file);
        
printf("ioctl_upload_before_eval: din %x \n",top->ioctl_din);
                ioctl_next_addr++;
            }
        }
    }
    else {
    top->ioctl_upload=0;
    top->ioctl_wr=0;
    }

}
int nextchar = 0;
int uploadnextchar = 0;
void ioctl_upload_after_eval()
{
    top->ioctl_addr=ioctl_next_addr;
uploadnextchar=top->ioctl_din;
if (ioctl_upload_file) printf("ioctl_upload_after_eval %x wr %x dl %x\n",top->ioctl_addr,top->ioctl_wr,top->ioctl_upload);
}


void ioctl_download_setfile(char *file, int index)
{
    ioctl_next_addr = -1;
    top->ioctl_addr=ioctl_next_addr;
    top->ioctl_index = index;
    ioctl_file=fopen(file,"rb");
    if (!ioctl_file) printf("error opening %s\n",file);
}
void ioctl_download_before_eval()
{
    if (ioctl_file) {
printf("ioctl_download_before_eval %x\n",top->ioctl_addr);
        if (top->ioctl_wait==0) {
        top->ioctl_download=1;
        top->ioctl_wr = 1;
        
        if (feof(ioctl_file)) {
            fclose(ioctl_file);
            ioctl_file=NULL;
            top->ioctl_download=0;
            top->ioctl_wr = 0;
            printf("finished upload\n");

        }
            if (ioctl_file) {
                int curchar = fgetc(ioctl_file);
    fprintf(stderr,"READ: %x\n",curchar);	
                if (curchar!=EOF) {
                //top->ioctl_dout=(char)curchar;
                nextchar=curchar;
printf("ioctl_download_before_eval: dout %x %x\n",top->ioctl_dout,nextchar);
                ioctl_next_addr++;
                }
            }
        }
    }
    else {
    top->ioctl_download=0;
    top->ioctl_wr=0;
    }

}
void ioctl_download_after_eval()
{
    top->ioctl_addr=ioctl_next_addr;
   top->ioctl_dout=(unsigned char)nextchar;
if (ioctl_file) printf("ioctl_download_after_eval %x wr %x dl %x %x\n",top->ioctl_addr,top->ioctl_wr,top->ioctl_download,top->ioctl_dout);
}

int my_count = 0;

static MemoryEditor mem_edit_1;


int main(int argc, char** argv, char** env) {
#ifdef WINDOWS
	// Create application window
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
	RegisterClassEx(&wc);
	HWND hwnd = CreateWindow(wc.lpszClassName, _T("Dear ImGui DirectX11 Example"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);

	// Initialize Direct3D
	if (CreateDeviceD3D(hwnd) < 0)
	{
		CleanupDeviceD3D();
		UnregisterClass(wc.lpszClassName, wc.hInstance);
		return 1;
	}

	// Show the window
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
#else
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
    {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }
 top = new Vtop();

    // Setup window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync
#endif

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

#ifdef WINDOWS
	// Setup Platform/Renderer bindings
	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
#else
    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL2_Init();

#endif

	Verilated::commandArgs(argc, argv);
	
	memset(disp_ptr, 0xAA, disp_size);
	//memset(ram_ptr, 0x00, ram_size);
	srand(1);
    for (int i=0; i<ram_size/4; i++)
    {
        ram_ptr[i]=rand();
    }

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

#ifdef WINDOWS
	// Upload texture to graphics system
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = 800;
	desc.Height = 525;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	//desc.Format = DXGI_FORMAT_B5G5R5A1_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	ID3D11Texture2D *pTexture = NULL;
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = disp_ptr;
	//subResource.pSysMem = vga_ptr;
	subResource.SysMemPitch = desc.Width * 4;
	subResource.SysMemSlicePitch = 0;
	g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

	// Create texture view
	D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
	ZeroMemory(&srvDesc, sizeof(srvDesc));
	srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srvDesc.Texture2D.MipLevels = desc.MipLevels;
	srvDesc.Texture2D.MostDetailedMip = 0;
	g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, &g_pFontTextureView);
	pTexture->Release();

	// Store our identifier
	ImTextureID my_tex_id = (ImTextureID)g_pFontTextureView;

	
	// Create texture sampler
	{
		D3D11_SAMPLER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		desc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		desc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		desc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		desc.MipLODBias = 0.f;
		desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		desc.MinLOD = 0.f;
		desc.MaxLOD = 0.f;
		g_pd3dDevice->CreateSamplerState(&desc, &g_pFontSampler);
	}
#else
    // the texture should match the GPU so it doesn't have to copy
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);



	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, VGA_WIDTH, VGA_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE,disp_ptr);
    ImTextureID my_tex_id = (ImTextureID) tex;


    //ImTextureID my_tex_id = (ImTextureID) renderedTexture;
#endif

	bool follow_writes = 0;
	int write_address = 0;

	static bool show_app_console = true;

#ifdef WINDOWS
	// imgui Main loop stuff...
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		// Poll and handle messages (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		// Start the Dear ImGui frame
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
#else
    // Main loop
    bool done = false;
    while (!done)
    {
    	// Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);

#endif

		ImGui::NewFrame();

		ImGui::Begin("Virtual Dev Board v1.0");		// Create a window called "Virtual Dev Board v1.0" and append into it.

		ShowExampleAppConsole(&show_app_console);

#if 0
		//ImGui::Text("samp_index = %d", samp_index);
		//ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		//ImGui::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, "sample", -1.0f, 1.0f, ImVec2(0, 80));
#endif
		if (ImGui::Button("RESET")) {
		    main_time = 0;
		    top->reset = 1;
		    memset(disp_ptr, 0xaa, BUF_WIDTH*BUF_HEIGHT*4);
		    line_count = 0;
		    pix_count = 0;
		    //memset(ram_ptr, 0, ram_size);
		}
		ImGui::Text("main_time %d", main_time);
		ImGui::Text("frame_count: %d  line_count: %d", frame_count, line_count);
		ImGui::Text("Addr:   0x%04X", top->top__DOT__gigatron_shell__DOT__gigatron__DOT__ram__DOT__gigatron_ram_inst__DOT__address);
		ImGui::Text("PC:     0x%04X", top->top__DOT__gigatron_shell__DOT__gigatron__DOT__cpu__DOT__PC);
		ImGui::Text("Instruction:     0x%04X", top->top__DOT__gigatron_shell__DOT__gigatron__DOT__eeprom__DOT__data__out__out0);
		ImGui::Text("HS:     %d", top->top__DOT__VGA_HS);
		ImGui::Text("VS:     %d", top->top__DOT__VGA_VS);

		ImGui::Checkbox("RUN", &run_enable);

		if (single_step == 1) single_step = 0;
		if (ImGui::Button("Single Step")) {
			run_enable = 0;
			single_step = 1;
		}

		if (multi_step == 1) multi_step = 0;
		if (ImGui::Button("Multi Step")) {
			run_enable = 0;
			multi_step = 1;
		}
		ImGui::SameLine(); ImGui::SliderInt("Step amount", &multi_step_amount, 8, 1000000);
		ImGui::Image(my_tex_id, ImVec2(VGA_WIDTH, VGA_HEIGHT));
		ImGui::End();


#if 1
		ImGui::Begin("RAM Editor");
		mem_edit_1.DrawContents(ram_ptr, ram_size, 0);
		ImGui::End();
#endif		

#ifdef WINDOWS
		// Update the texture!
		// D3D11_USAGE_DEFAULT MUST be set in the texture description (somewhere above) for this to work.
		// (D3D11_USAGE_DYNAMIC is for use with map / unmap.) ElectronAsh.
		g_pd3dDeviceContext->UpdateSubresource(pTexture, 0, NULL, disp_ptr, BUF_WIDTH * 4, 0);

		// Rendering
		ImGui::Render();
		g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
		g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		//g_pSwapChain->Present(1, 0); // Present with vsync
		g_pSwapChain->Present(0, 0); // Present without vsync
#else

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, VGA_WIDTH, VGA_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE,disp_ptr);

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        //glUseProgram(0); // You may want this if using this code in an OpenGL 3+ context where shaders may be bound
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
#endif


		if (run_enable) 
        {
            if (frame_count <6) {
                for (int step = 0; step < 500000; step++) verilate();	// Simulates MUCH faster if it's done in batches.
            } else {
                for (int step = 0; step < 4096; step++) verilate();	// Simulates MUCH faster if it's done in batches.
            }
        }
		else {																// But, that will affect the values we can grab for the GUI.
			if (single_step) verilate();
			if (multi_step) for (int step = 0; step < multi_step_amount; step++) verilate();
		}
	}
#ifdef WINDOWS
	// Close imgui stuff properly...
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
	DestroyWindow(hwnd);
	UnregisterClass(wc.lpszClassName, wc.hInstance);
#else
    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
#endif
	return 0;
}
