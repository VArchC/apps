RISCV_PREFIX=riscv64-unknown-elf-

CC			=$(RISCV_PREFIX)gcc
LD			=$(RISCV_PREFIX)gcc

CFLAGS	= -O3
LFLAGS	=
HEADERS = src
INCLUDE =

TARGET	=bzip2
EXE			=bin/$(TARGET).rv

SRC_FILES = blocksort.c  bzlib.c  compress.c  crctable.c  ctuning-rtl.c  decompress.c  huffman.c  randtable.c bzip2.c
OBJ_FILES = $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o)))

.PHONY: all clean
	
all: DIR $(EXE)

DIR: clean
	@mkdir bin -p
	@mkdir obj -p

$(EXE): $(OBJ_FILES)
	$(LD) $^ $(LFLAGS) -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf bin
	@rm -rf obj
