RISCV_PREFIX ?= riscv64-unknown-elf-
RISCV_GCC ?= $(RISCV_PREFIX)gcc
CC			:= $(RISCV_GCC)
LD			:= $(RISCV_GCC)



TARGET=nbody

SRC_FILES := src/nbody.c
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o))) 

#AFLAGS = -DAPPROX
CFLAGS = -O3 -static  #-I$(LOCAL)/riscv-tools/riscv-isa-sim/build/ $(AFLAGS)
LFLAGS = -lm 


EXE = bin/$(TARGET).rv

all: DIR $(EXE)

DIR:
	mkdir -p obj 
	mkdir -p bin

$(EXE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^  $(LFLAGS) 

#$(OBJ_FILES): src/%.c
obj/%.o: $(SRC_FILES)
	$(CC) ${CFLAGS} -c -o $@ $< 

clean:
	rm -rf bin
	rm -rf obj
