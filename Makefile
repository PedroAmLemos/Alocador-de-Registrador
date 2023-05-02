# Name of the project
PROJ_NAME=regalloc

# .c files
C_SOURCE=$(wildcard *.cpp)

# .h files
H_SOURCE=$(wildcard *.hpp)

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=g++

# Flags for compiler
CC_FLAGS=-std=c++11   \
		 -g

#LINKER_FLAGS = -lm

#
# Compilation and linking
#
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS) $(LINKER_FLAGS)

%.o: %.c %.h
	$(CC) -o $@ $< -c $(CC_FLAGS) $(LINKER_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< -c $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~
