# Basic Makefile
# Source / Credit:
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# Makefile structure:
# 	- .h files in an include directory found in the project root
#   - source code will be under src directory
#   - local libraries under lib directory
# 	- place .o files in their own directory / obj dir

# Compiler version: 
# clang version 14.0.6
# Target: x86_64-unknown-linux-gnu
# Thread model: posix
# InstalledDir: /nix/store/pl4kwicji3vr968vd8j8lh934m6f9bkh-clang-14.0.6/bin

# Some notes:
# hellomake: hellomake.c hellofunc.c
# 	clang -g -Wall -o hellomake hellomake.c hellofunc.c -I.

# $(CC) -g -Wall -o $@ $^ $(CFLAGS)

# baseline compiler flags

TARGET = 
CC = clang

CFLAGS += -I$(IDIR) -g3 -Wall
CFLAGS += -Wextra -Wconversion -Wdouble-promotion 
CFLAGS += -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion 
GFLAGS += -fsanitize=undefined -fsanitize-trap

IDIR = include
# SRCDIR = src
SRCEXT = c
OBJDIR = obj
# LIBDIR = lib

BINDIR = bin
BINNAME = hello

# other libs
LIBS = -lm

_DEPS = queue.h customer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o queue.o customer.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

BIN = $(BINDIR)/$(BINNAME)

$(BIN): $(OBJS)
	@mdkir -p $(BINDIR)
	$(CC)  $^ -o $(BIN) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# $(OBJDIR)/%.o: $(SRCDIR)%.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# a.out: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o *~ core $(INCDIR)/*~ 
	rm -r $(BUILDDIR) $(BINDIR)
	rm -f *.out