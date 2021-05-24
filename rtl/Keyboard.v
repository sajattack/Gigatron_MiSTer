module Keyboard (
    input [10:0] ps2_key,
    input pulse,
    output reg [7:0] ascii_code
);

    reg ps2_changed;
    reg ps2_released;
    reg old_state;

    always @(posedge pulse) begin

        old_state <= ps2_key[10];
        ps2_changed <= (old_state != ps2_key[10]);
        ps2_released <= ~ps2_key[9];

        if(ps2_changed) begin
            case (ps2_key[7:0])
                8'h0d: ascii_code <= 8'd9;
                8'h5a: ascii_code <= 8'd10;
                8'h76: ascii_code <= 8'd27;
                8'h29: ascii_code <= " ";
                8'h52: ascii_code <= "'";
                8'h7c: ascii_code <= "*";
                8'h79: ascii_code <= "+";
                8'h41: ascii_code <= ",";
                8'h4e: ascii_code <= "-";
                8'h7b: ascii_code <= "-";
                8'h49: ascii_code <= ".";
                8'h71: ascii_code <= ".";
                8'h4a: ascii_code <= "/";
                8'h45: ascii_code <= "0";
                8'h70: ascii_code <= "0";
                8'h16: ascii_code <= "1";
                8'h69: ascii_code <= "1";
                8'h1e: ascii_code <= "2";
                8'h72: ascii_code <= "2";
                8'h26: ascii_code <= "3";
                8'h7a: ascii_code <= "3";
                8'h25: ascii_code <= "4";
                8'h6b: ascii_code <= "4";
                8'h2e: ascii_code <= "5";
                8'h73: ascii_code <= "5";
                8'h36: ascii_code <= "6";
                8'h74: ascii_code <= "6";
                8'h3d: ascii_code <= "7";
                8'h6c: ascii_code <= "7";
                8'h3e: ascii_code <= "8";
                8'h75: ascii_code <= "8";
                8'h46: ascii_code <= "9";
                8'h7d: ascii_code <= "9";
                8'h4c: ascii_code <= ";";
                8'h55: ascii_code <= "=";
                8'h1c: ascii_code <= "a";
                8'h32: ascii_code <= "b";
                8'h21: ascii_code <= "c";
                8'h23: ascii_code <= "d";
                8'h24: ascii_code <= "e";
                8'h2b: ascii_code <= "f";
                8'h34: ascii_code <= "g";
                8'h33: ascii_code <= "h";
                8'h43: ascii_code <= "i";
                8'h3b: ascii_code <= "j";
                8'h42: ascii_code <= "k";
                8'h4b: ascii_code <= "l";
                8'h3a: ascii_code <= "m";
                8'h31: ascii_code <= "n";
                8'h44: ascii_code <= "o";
                8'h4d: ascii_code <= "p";
                8'h15: ascii_code <= "q";
                8'h2d: ascii_code <= "r";
                8'h1b: ascii_code <= "s";
                8'h2c: ascii_code <= "t";
                8'h3c: ascii_code <= "u";
                8'h2a: ascii_code <= "v";
                8'h1d: ascii_code <= "w";
                8'h22: ascii_code <= "x";
                8'h35: ascii_code <= "y";
                8'h1a: ascii_code <= "z";
                8'h5d: ascii_code <= 8'd92;
                8'h5b: ascii_code <= "]";
                8'h0e: ascii_code <= "`";
                8'h66: ascii_code <= 8'd127; // backspace
                default: ascii_code <= 8'd255;
            endcase
        end else if (ps2_released)
            ascii_code <=8'd255;
        else
            ascii_code <= ascii_code;
    end
endmodule


