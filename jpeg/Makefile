RISCV_PREFIX ?= riscv64-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
CC			:= $(RISCV_GCC)
LD			:= $(RISCV_GCC)



TARGET=jpeg

SRC_FILES := src/dct.cpp src/encoder.cpp src/huffman.cpp src/marker.cpp src/quant.cpp src/rgbimage.cpp src/jpeg.cpp
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.cpp=.o))) 

#AFLAGS = -DAPPROX
CFLAGS		:= -O3 -Wall -std=c++11  -g $(AFLAGS)
LFLAGS = -lm $(AFLAGS)

TMP=/tmp/

EXE = bin/$(TARGET).rv

all: DIR $(EXE)

DIR:
	mkdir -p obj 
	mkdir -p bin

$(EXE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS) 

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf bin
	rm -rf obj
