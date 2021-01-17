all:
	verilator --cc verilator_top.v ../rtl/gigatron_shell.sv ../rtl/gigatron_onefile.sv -I../rtl -I/usr/lib/ --exe SDL2_sim.cpp -LDFLAGS "-lSDL2main -lSDL2" --public
	make -C obj_dir -f Vverilator_top.mk OPT_FAST='-O3'
clean: 
	rm -rf obj_dir
