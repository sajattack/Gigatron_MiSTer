module spram #(parameter addr_width=15, parameter data_width=8) 
   (
	input logic clock,
	input logic wren/*verilator public_flat*/,
	input logic [(data_width-1):0] data/*verilator public_flat*/,
	input logic cs,
	input logic [(addr_width-1):0] address/*verilator public_flat*/,
	output logic [(data_width-1):0] q/*verilator public_flat*/
);

	reg [(data_width-1):0] mem [(2**addr_width-1):0]/*verilator public_flat*/;
	
	always_ff @(posedge clock)
	 begin
		if (wren) mem[address] <= data;
	//$display("RAM: data=%h addr=%h wren=%b cs=%b q=%h",data, address, wren, cs, q);
	end

	assign q= cs ? mem[address] : {data_width{1'b1}};

endmodule: spram
