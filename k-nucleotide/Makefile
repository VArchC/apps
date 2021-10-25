RISCV_PREFIX=riscv64-unknown-elf-

CC			=$(RISCV_PREFIX)gcc
LD			=$(RISCV_PREFIX)gcc

CFLAGS	= -O3 
LFLAGS	= -static #-fopenmp
HEADERS = src
INCLUDE = -Isrc/

TARGET	=k-nucleotide
EXE			=bin/$(TARGET).rv

SRC_FILES = src/knucleotide.c
OBJ_FILES=$(addprefix obj/,$(notdir $(SRC_FILES:.c=.o)))


.PHONY: all clean
	
all: DIR $(EXE)

DIR: clean
	@mkdir bin -p
	@mkdir obj -p

$(EXE): $(OBJ_FILES)
	$(LD) $^ $(LFLAGS) -o $@

$(OBJ_FILES): $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf bin
	@rm -rf obj
