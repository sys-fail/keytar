#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)
COMPONENT_SRCDIRS := .

c_startup.o: $(COMPONENT_PATH)/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(addprefix -I ,$(COMPONENT_INCLUDES)) $(addprefix -I ,$(COMPONENT_EXTRA_INCLUDES)) -c $< -o $@

startup.o: c_startup.o $(COMPONENT_PATH)/main.o
	$(LD) -r c_startup.o $(COMPONENT_PATH)/main.o -o $@

main.o:
	opam init -a --compiler=4.06.0+32bit
	git clone https://github.com/well-typed-lightbulbs/ocaml-esp32.git ocaml-esp32
	cd ocaml-esp32; git checkout 4.06-esp32+lto; opam config exec -- ./configure -target xtensa-esp32-elf -lto -flambda -target-bindir /esp/ocaml-esp32/bin -prefix /esp/ocaml-esp32; opam config exec -- make world-cross -j; opam config exec -- make install-cross;
	opam config exec -- ocamlrun $(CURDIR)/ocaml-esp32/bin/ocamlopt hello_caml.ml -output-complete-obj -o main/main.o

.PHONY: build
build: startup.o
