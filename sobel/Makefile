RISCV_PREFIX=riscv64-unknown-elf-
CC			=$(RISCV_PREFIX)gcc
LD			=$(RISCV_PREFIX)gcc

RISCV_PATH=$(RISCV)/include/adele

CFLAGS	= -O3 #-std=c99
CFLAGS += $(FLAGS)
LFLAGS	= -lm
HEADERS = src
INCLUDE =  -I$(RISCV_PATH)
LIB			= 

TARGET	=sobel
EXE			=bin/$(TARGET).rv

SRC_FILES := sobel.c
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o)))

.PHONY: all clean
	
all: DIR $(EXE)

DIR:
	@mkdir bin -p
	@mkdir obj -p

$(EXE): $(OBJ_FILES)
	$(LD) $^ $(LIB) $(LFLAGS) -o $@

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf bin
	@rm -rf obj
