# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./lib

# Directories
SRCDIR = ./src
LIBDIR = ./lib

# Find all source files and corresponding object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Executable
EXEC = sort

# Default target
all: $(EXEC)

# Build executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	rm -f $(OBJS) # Automatically delete object files

# Compile each source file into an object file
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(LIBDIR)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(EXEC)

# PHONY targets
.PHONY: all clean
