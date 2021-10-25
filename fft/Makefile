
RISCV_PREFIX=riscv64-unknown-elf-
CC		=	$(RISCV_PREFIX)gcc


TARGET=fft


CFLAGS = -static -O3  -Isrc/ 
LFLAGS = -lm

SRC_FILES := src/fftmisc.c src/fourierf.c src/main.c
OBJ_FILES := $(addprefix obj/,$(notdir $(SRC_FILES:.c=.o))) 
#OBJ = fftmisc.o  fourierf.o

EXE = bin/$(TARGET).rv

all: DIR $(EXE)

DIR:
	mkdir -p bin
	mkdir -p obj

$(EXE): ${OBJ_FILES}
	$(CC) $(CFLAGS)  -o $@ $^  $(LFLAGS)

obj/%.o: src/%.c
	$(CC) ${CFLAGS} -c -o $@ $< 

clean:
	rm -rf bin
	rm -rf obj
