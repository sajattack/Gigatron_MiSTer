module Keyboard (
    input [2:0] kb_lang,
    input [10:0] ps2_key,
    input pulse,
    input reset,
    output reg caps_lock = 0,
    output [7:0] ascii_code
);


    localparam kb_US = 3'd0;
    localparam kb_GB = 3'd1;
    localparam kb_DE = 3'd2;
    localparam kb_FR = 3'd3;
    localparam kb_IT = 3'd4;
    localparam kb_ES = 3'd5;
    localparam k_F0 = 8'd192;
    localparam NONE = 8'hFF;

    wire [2:0] lang = kb_lang;

    wire ps2_pressed = ps2_key[9];
    wire ps2_released = ~ps2_pressed;
    reg old_ps2_stb = 0;
    reg old_reset = 0;
    reg SHIFT_L = 0;
    reg SHIFT_R = 0;
    reg CTRL_L = 0;
    reg CTRL_R = 0;
    reg ALT_L = 0;
    reg ALT_R = 0;
    reg [7:0] joy_key = 8'hff;
    reg [7:0] ascii_key = 8'hff;
    wire SHIFT = SHIFT_L | SHIFT_R;
    wire CTRL = CTRL_L | CTRL_R;
    wire ALT = ALT_L | ALT_R;
    wire ps2_changed = (old_ps2_stb ^ ps2_key[10]);
    wire [7:0] CAPSTOGGLE = (SHIFT ^ caps_lock) ? 8'h00 : 8'h20;
    wire [7:0] CTRLMASK = CTRL ? 8'h1f : 8'hff;
    wire [8:0] keycode = ps2_key[8:0];

    assign ascii_code = ascii_key & joy_key;

    always @(posedge pulse) begin
        old_ps2_stb <= ps2_key[10];
        old_reset <= reset;
        if (reset & ~old_reset)
            caps_lock <= 0;
        else if (ps2_changed) begin
            // Handle modifier keys, which need to be cached
            case (keycode)
                // Modifier keys
                9'h012: begin ascii_key <= NONE; SHIFT_L <= ps2_pressed; end
                9'h059: begin ascii_key <= NONE; SHIFT_R <= ps2_pressed; end
                9'h014: begin ascii_key <= NONE; CTRL_L  <= ps2_pressed; end
                9'h114: begin ascii_key <= NONE; CTRL_R  <= ps2_pressed; end
                9'h011: begin ascii_key <= NONE; ALT_L   <= ps2_pressed; end
                9'h111: begin ascii_key <= NONE; ALT_R   <= ps2_pressed; end
                9'h058: begin ascii_key <= NONE; caps_lock <= caps_lock ^ ps2_pressed; end
                default: begin end
            endcase

            // Handle AltGr modifier for DeFrItEs
            if (ALT_R) begin
                case (lang)
                kb_DE:
                    case (keycode)
                    9'h15: ascii_key <= "@" & CTRLMASK;
                    9'h3d: ascii_key <= "{";
                    9'h3e: ascii_key <= "[" & CTRLMASK;
                    9'h45: ascii_key <= "}";
                    9'h46: ascii_key <= "]" & CTRLMASK;
                    9'h4e: ascii_key <= 8'h5c & CTRLMASK;
                    9'h5b: ascii_key <= "~";
                    9'h5d: ascii_key <= "#";
                    9'h61: ascii_key <= "|";
                    default: ascii_key <= NONE;
                    endcase
                kb_FR:
                    case (keycode)
                    9'h15: ascii_key <= "@" & CTRLMASK; // ?? maybe a bug in PS2.ino
                    9'h1e: ascii_key <= "~";
                    9'h25: ascii_key <= "{" & CTRLMASK;
                    9'h26: ascii_key <= "#";
                    9'h2e: ascii_key <= "[" & CTRLMASK;
                    9'h36: ascii_key <= "|";
                    9'h3d: ascii_key <= "`";
                    9'h3e: ascii_key <= 8'h5c & CTRLMASK;
                    9'h45: ascii_key <= "@" & CTRLMASK;
                    9'h46: ascii_key <= "^" & CTRLMASK;
                    9'h4e: ascii_key <= "]" & CTRLMASK;
                    9'h55: ascii_key <= "}"; // 0x56 in PS2.ino, clearly a bug
                    //9'h5d: ascii_key <= "#";  // not in any layout I've seen
                                                // maybe it was confused with U+00A4 which looks similar
                    9'h61: ascii_key <= "|";
                    default: ascii_key <= NONE;
                    endcase
                kb_IT:
                    case (keycode)
                    9'h3d: ascii_key <= "{";
                    9'h3e: ascii_key <= "[" & CTRLMASK;
                    9'h45: ascii_key <= "}";
                    9'h46: ascii_key <= "]" & CTRLMASK;
                    9'h4c: ascii_key <= "@" & CTRLMASK;
                    9'h4e: ascii_key <= "`";
                    9'h52: ascii_key <= "#";
                    9'h54: ascii_key <= "[" & CTRLMASK;
                    9'h55: ascii_key <= "~";
                    9'h5b: ascii_key <= "]" & CTRLMASK;
                    default: ascii_key <= NONE;
                    endcase
                kb_ES:
                    case (keycode)
                    9'h0e: ascii_key <= 8'h5c & CTRLMASK;
                    9'h16: ascii_key <= "|";
                    9'h1e: ascii_key <= "@" & CTRLMASK;
                    9'h25: ascii_key <= "~";
                    9'h26: ascii_key <= "#";
                    9'h52: ascii_key <= "{";
                    9'h54: ascii_key <= "[" & CTRLMASK;
                    9'h5b: ascii_key <= "]" & CTRLMASK;
                    9'h5d: ascii_key <= "}";
                    9'h61: ascii_key <= "|";
                    default: ascii_key <= NONE;
                    endcase
                default: ascii_key <= NONE;
                endcase

            end else begin // Not AltGr

                case (keycode)
                    // Function keys
                    9'h05: ascii_key <= k_F0 + 8'd1;
                    9'h06: ascii_key <= k_F0 + 8'd2;
                    9'h04: ascii_key <= k_F0 + 8'd3;
                    9'h0c: ascii_key <= k_F0 + 8'd4;
                    9'h03: ascii_key <= k_F0 + 8'd5;
                    9'h0b: ascii_key <= k_F0 + 8'd6;
                    9'h83: ascii_key <= k_F0 + 8'd7;
                    9'h0a: ascii_key <= k_F0 + 8'd8;
                    9'h01: ascii_key <= k_F0 + 8'd9;
                    9'h09: ascii_key <= k_F0 +8'd10;
                    9'h78: ascii_key <= k_F0 +8'd11;
                    9'h07: ascii_key <= k_F0 +8'd12;    // FIXME: F12 is for menu, this won't work
                                                        // How to make F12 usable in the framework?
                                                        // Is it worth, for this computer?

                    // Controller emulation (of sorts)
                    9'h174: joy_key[0] <= ps2_released;     // Right
                    9'h16b: joy_key[1] <= ps2_released;     // Left
                    9'h172: joy_key[2] <= ps2_released;     // Down
                    9'h175: joy_key[3] <= ps2_released;     // Up
                    9'h17d: joy_key[4] <= ps2_released;     // PgUp = Start
                    9'h171: if (CTRL & ALT) joy_key[4] <= ps2_released; 
                        else joy_key[7] <= ps2_released;    // CtrlAltDel = start, Del = A
                    9'h17a: joy_key[5] <= ps2_released;     // PgDn = Select (change scanlines)
                    9'h170, 9'h16c:
                            joy_key[6] <= ps2_released;     // Home, Ins = button B
                    9'h169: joy_key[7] <= ps2_released;     // End = ButtonA

                    // Keys that generate control codes, not country-specific, incl. space
                    9'h0d:  ascii_key <= 8'h09;   // Tab
                    9'h5a, 9'h15a:
                            ascii_key <= 8'h0a;  // Return, KP Enter
                    9'h76:  ascii_key <= 8'h1b;  // Esc
                    9'h66:  ascii_key <= 8'h7f; // Backspace
                    9'h29:  ascii_key <= " ";

                    // Top-row numbers, mostly country-specific
                    9'h16:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "1" : "&";
                        default:ascii_key <= SHIFT ? "!" : "1";
                        endcase
                    9'h1e:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "2" : NONE;
                        kb_US:  ascii_key <= SHIFT ? "@" : "2";
                        default:ascii_key <= SHIFT ? "\"": "2";
                        endcase
                    9'h26:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "3" : "\"";
                        kb_US:  ascii_key <= SHIFT ? "#" : "3";
                        default:ascii_key <= SHIFT ? NONE : "3";
                        endcase
                    9'h25:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "4" : "'";
                        default:ascii_key <= SHIFT ? "$" : "4";
                        endcase
                    9'h2e:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "5" : "(";
                        default:ascii_key <= SHIFT ? "%" : "5";
                        endcase
                    9'h36:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "6" : "-";
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? ("^" & CTRLMASK) : "6";
                        default:ascii_key <= SHIFT ? "&" : "6";
                        endcase
                    9'h3d:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "7" : NONE;
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "&" : "7";
                        default:ascii_key <= SHIFT ? "/" : "7";
                        endcase
                    9'h3e:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "8" : ("_" & CTRLMASK);
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "*" : "8";
                        default:ascii_key <= SHIFT ? "(" : "8";
                        endcase
                    9'h46:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "9" : NONE;
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "(" : "9";
                        default:ascii_key <= SHIFT ? ")" : "9";
                        endcase
                    9'h45:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "0" : NONE;
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? ")" : "0";
                        default:ascii_key <= SHIFT ? "=" : "0";
                        endcase

                    // Keypad
                    9'h71: ascii_key <= ".";
                    9'h7b: ascii_key <= "-";
                    9'h79: ascii_key <= "+";
                    9'h7c: ascii_key <= "*";
                    9'h14a:ascii_key <= "/";
                    9'h70: ascii_key <= "0";
                    9'h69: ascii_key <= "1";
                    9'h72: ascii_key <= "2";
                    9'h7a: ascii_key <= "3";
                    9'h6b: ascii_key <= "4";
                    9'h73: ascii_key <= "5";
                    9'h74: ascii_key <= "6";
                    9'h6c: ascii_key <= "7";
                    9'h75: ascii_key <= "8";
                    9'h7d: ascii_key <= "9";

                    // Rest of symbol keys
                    9'h0e:
                        case (lang)
                        kb_IT:  ascii_key <= SHIFT ? "|" : (8'h5c & CTRLMASK);
                        kb_DE:  ascii_key <= SHIFT ? NONE : ("^" & CTRLMASK);
                        kb_GB:  ascii_key <= SHIFT ? NONE : "`";
                        kb_US:  ascii_key <= SHIFT ? "~" : "`";
                        default:ascii_key <= NONE;
                        endcase
                    9'h4c:
                        case (lang)
                        kb_FR:  ascii_key <= ("M" | CAPSTOGGLE) & CTRLMASK;
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? ":" : ";";
                        default:ascii_key <= NONE;
                        endcase
                    9'h41:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "." : ";";
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "<" : ",";
                        default:ascii_key <= SHIFT ? ";" : ",";
                        endcase
                    9'h49:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "/" : ":";
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? ">" : ".";
                        default:ascii_key <= SHIFT ? ":" : ".";
                        endcase
                    9'h4a:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? NONE : "!";
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? (CTRL ? 8'h7f : "?") : "/";
                        default:ascii_key <= SHIFT ? ("_" & CTRLMASK) : "-";
                        endcase
                    9'h4e:
                        case (lang)
                        kb_IT, kb_ES:
                                ascii_key <= SHIFT ? (CTRL ? 8'h7f : "?") : "'";
                        kb_DE:  ascii_key <= SHIFT ? (CTRL ? 8'h7f : "?") : NONE;
                        kb_FR:  ascii_key <= SHIFT ? NONE : ")";
                        default:ascii_key <= SHIFT ? ("_" & CTRLMASK) : "-";
                        endcase
                    9'h52:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? "%" : NONE;
                        kb_US:  ascii_key <= SHIFT ? "\"" : "'";
                        kb_GB:  ascii_key <= SHIFT ? "@" : "'";
                        default:ascii_key <= NONE;
                        endcase
                    9'h54:
                        case (lang)
                        kb_ES:  ascii_key <= SHIFT ? ("^" & CTRLMASK) : "`";
                        kb_FR:  ascii_key <= SHIFT ? NONE : ("^" & CTRLMASK);
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "{" : ("[" & CTRLMASK);
                        default:ascii_key <= NONE;
                        endcase
                    9'h55:
                        case (lang)
                        kb_DE:  ascii_key <= SHIFT ? "`" : "'";
                        kb_IT:  ascii_key <= SHIFT ? ("^" & CTRLMASK) : NONE;
                        kb_ES:  ascii_key <= NONE;
                        default:ascii_key <= SHIFT ? "+" : "=";
                        endcase
                    9'h5b:
                        case (lang)
                        kb_FR:  ascii_key <= SHIFT ? NONE : "$";
                        kb_US, kb_GB:
                                ascii_key <= SHIFT ? "}" : ("]" & CTRLMASK);
                        default:ascii_key <= SHIFT ? "*" : "+";
                        endcase
                    9'h5d:
                        case (lang)
                        kb_US:  ascii_key <= SHIFT ? "|" : (8'h5c & CTRLMASK);
                        kb_GB:  ascii_key <= SHIFT ? "~" : "#";
                        kb_DE:  ascii_key <= SHIFT ? "'" : "#";
                        kb_FR:  ascii_key <= SHIFT ? NONE : "*";
                        default:ascii_key <= NONE;
                        endcase
                    9'h61:
                        case (lang)
                        kb_US:  ascii_key <= NONE;
                        kb_GB:  ascii_key <= SHIFT ? "|" : (8'h5c & CTRLMASK);
                        default:ascii_key <= SHIFT ? ">" : "<";
                        endcase


                    // Letters (except French "M")
                    9'h1c: ascii_key <= ((lang == kb_FR ? "Q" : "A") | CAPSTOGGLE) & CTRLMASK;
                    9'h32: ascii_key <= ("B" | CAPSTOGGLE) & CTRLMASK;
                    9'h21: ascii_key <= ("C" | CAPSTOGGLE) & CTRLMASK;
                    9'h23: ascii_key <= ("D" | CAPSTOGGLE) & CTRLMASK;
                    9'h24: ascii_key <= ("E" | CAPSTOGGLE) & CTRLMASK;
                    9'h2b: ascii_key <= ("F" | CAPSTOGGLE) & CTRLMASK;
                    9'h34: ascii_key <= ("G" | CAPSTOGGLE) & CTRLMASK;
                    9'h33: ascii_key <= ("H" | CAPSTOGGLE) & CTRLMASK;
                    9'h43: ascii_key <= ("I" | CAPSTOGGLE) & CTRLMASK;
                    9'h3b: ascii_key <= ("J" | CAPSTOGGLE) & CTRLMASK;
                    9'h42: ascii_key <= ("K" | CAPSTOGGLE) & CTRLMASK;
                    9'h4b: ascii_key <= ("L" | CAPSTOGGLE) & CTRLMASK;
                    9'h3a: if (lang == kb_FR) ascii_key <= SHIFT ? (CTRL ? 8'h7f : "?") : ",";
                        else ascii_key <= ("M" | CAPSTOGGLE) & CTRLMASK;
                    9'h31: ascii_key <= ("N" | CAPSTOGGLE) & CTRLMASK;
                    9'h44: ascii_key <= ("O" | CAPSTOGGLE) & CTRLMASK;
                    9'h4d: ascii_key <= ("P" | CAPSTOGGLE) & CTRLMASK;
                    9'h15: ascii_key <= ((lang == kb_FR ? "A" : "Q") | CAPSTOGGLE) & CTRLMASK;
                    9'h2d: ascii_key <= ("R" | CAPSTOGGLE) & CTRLMASK;
                    9'h1b: ascii_key <= ("S" | CAPSTOGGLE) & CTRLMASK;
                    9'h2c: ascii_key <= ("T" | CAPSTOGGLE) & CTRLMASK;
                    9'h3c: ascii_key <= ("U" | CAPSTOGGLE) & CTRLMASK;
                    9'h2a: ascii_key <= ("V" | CAPSTOGGLE) & CTRLMASK;
                    9'h1d: ascii_key <= ((lang == kb_FR ? "Z" : "W") | CAPSTOGGLE) & CTRLMASK;
                    9'h22: ascii_key <= ("X" | CAPSTOGGLE) & CTRLMASK;
                    9'h35: ascii_key <= ((lang == kb_DE ? "Z" : "Y") | CAPSTOGGLE) & CTRLMASK;
                    9'h1a: ascii_key <= ((lang == kb_FR ? "W" : lang == kb_DE ? "Y" : "Z" ) | CAPSTOGGLE) & CTRLMASK;
                    default: ascii_key <= 8'hff;
                endcase
            end
        end else if (ps2_released)
            ascii_key <= 8'hff;
    end

endmodule
