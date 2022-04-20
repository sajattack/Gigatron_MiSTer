verilator \
-cc -exe --public --trace --savable \
--compiler msvc +define+SIMULATION=1 \
-O3 --x-assign fast --x-initial fast --noassert \
--converge-limit 6000 \
-Wno-UNOPTFLAT \
--top-module top sim.v \
../rtl/gigatron_eeprom_from_file.sv \
../rtl/gigatron_onefile.sv \
../rtl/gigatron_option_rom.sv \
../rtl/gigatron_ram_bb.v \
../rtl/gigatron_shell.sv \
../rtl/Keyboard.v \
../rtl/menlo_babelfish.sv \
../rtl/spram.sv \
../rtl/vga_controller_with_sprite.sv \
../rtl/x74xx153.sv \
-I../rtl/pll