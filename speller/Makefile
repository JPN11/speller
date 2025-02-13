# Makefile for the Speller Project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g

# Source files
SRC = dictionary.c speller.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = speller

# Default target
all: $(EXEC)

# Linking the object files to create the executable
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

# Compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean target to remove compiled files
clean:
	rm -f $(OBJ) $(EXEC)

# Specify dependencies
dictionary.o: dictionary.h
speller.o: dictionary.h
