#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := hello
CFLAGS := -g 

ESPRESSIF_DL := https://dl.espressif.com/dl/
XTENSA_TOOLCHAIN_TAR := xtensa-esp32-elf-linux64-1.22.0-80-g6c4433a-5.2.0.tar.gz

export IDF_PATH := $(CURDIR)/esp-idf
$(IDF_PATH)/make/project.mk:
	echo $(PATH)
	git clone --recursive https://github.com/well-typed-lightbulbs/esp-idf.git
	wget -c $(ESPRESSIF_DL)$(XTENSA_TOOLCHAIN_TAR)
	tar -xzf $(XTENSA_TOOLCHAIN_TAR)

include  $(IDF_PATH)/make/project.mk

