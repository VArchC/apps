RISCV_PREFIX := riscv64-unknown-elf-
CC			:= $(RISCV_PREFIX)g++
LD			:= $(RISCV_PREFIX)g++


CFLAGS		:= -std=c++11 -O3 #-lfann -lboost_regex -Wall
LFLAGS		:= #-lfann -lboost_regex -lParrot
HEADERS   := src
INCLUDE 	:= #-I${ANALOG_INC} -I${FANN_INC} -I${HEADERS}
LIB				:= #-L${ANALOG_LIB} -L${FANN_LIB} -L$(PARROT_LIB)

EXE 			= bin/jmeint.rv

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

.PHONY: all clean
	
all: DIR $(EXE)

DIR:
	@echo ${CPP_FILES}
	@echo ${OBJ_FILES}
	mkdir bin -p
	mkdir obj -p

$(EXE): $(OBJ_FILES)
	$(LD) $^ $(LIB) $(LFLAGS) -o $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf bin
	rm -rf obj
