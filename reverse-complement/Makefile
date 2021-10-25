RISCV_PREFIX=riscv64-unknown-elf-

CC			=$(RISCV_PREFIX)gcc
LD			=$(RISCV_PREFIX)gcc

CFLAGS	= -O3
LFLAGS	=
HEADERS = src
INCLUDE =

TARGET	=reverse-complement
EXE			=bin/$(TARGET).rv

SRC_FILES = reverse-complement.c
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
