RISCV_PREFIX=riscv64-unknown-elf-

TARGET=2mm
CC=$(RISCV_PREFIX)gcc

INCLUDE= -Isrc/

CFLAGS = -O3 -DPOLYBENCH_DUMP_ARRAYS $(INCLUDE) 

LFLAGS = 


SRC_FILES := src/polybench.c src/2mm.c 
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o))) 


EXE=bin/$(TARGET).rv

all: DIR $(EXE)

DIR:
	mkdir -p bin
	mkdir -p obj 

$(EXE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^ 

obj/%.o: src/%.c
	$(CC) ${CFLAGS} -c -o $@ $< 

clean:
	rm -rf bin
	rm -rf obj
