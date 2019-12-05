#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := hello
CFLAGS := -g 

ESPRESSIF_DL := https://dl.espressif.com/dl/
XTENSA_TOOLCHAIN_TAR := xtensa-esp32-elf-linux64-1.22.0-80-g6c4433a-5.2.0.tar.gz

export TOOLPREFIX := $(CURDIR)./xtensa-esp32-elf/bin/xtensa-esp32-elf-

xtensa-esp32-elf:
	wget -c $(ESPRESSIF_DL)$(XTENSA_TOOLCHAIN_TAR)
	tar -xzf $(XTENSA_TOOLCHAIN_TAR)


export IDF_PATH := $(CURDIR)/esp-idf
$(IDF_PATH)/make/project.mk:
	echo $(PATH)
	git clone --recursive https://github.com/well-typed-lightbulbs/esp-idf.git

path:
	echo $(PATH)

main/main.o:
	opam init -a --compiler=4.06.0+32bit
	git clone https://github.com/well-typed-lightbulbs/ocaml-esp32.git ocaml-esp32
	cd ocaml-esp32; git checkout 4.06-esp32+lto; opam config exec -- ./configure -target xtensa-esp32-elf -lto -flambda -target-bindir /esp/ocaml-esp32/bin -prefix /esp/ocaml-esp32; opam config exec -- make world-cross -j; opam config exec -- make install-cross;
	opam config exec -- ocamlrun $(CURDIR)/ocaml-esp32/bin/ocamlopt hello_caml.ml -output-complete-obj -o main/main.o

include  $(IDF_PATH)/make/project.mk
