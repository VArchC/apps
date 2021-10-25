RISCV_PREFIX=riscv64-unknown-elf-
CC			=$(RISCV_PREFIX)g++
LD			=$(RISCV_PREFIX)g++


CFLAGS	= -O3 -std=c++11 
LFLAGS	= 
HEADERS = src
INCLUDE = 
LIB			= 

TARGET	=blackscholes
EXE			=bin/$(TARGET).rv

SRC_FILES := blackscholes.c
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
	@rm -rf *.o
	@rm -rf *.d
	@rm -rf *.out
	@rm -rf bin
	@rm -rf obj
