# The compiler to use
CC = gcc

# The compiler flags
CFLAGS = -O0
CFLAGS_vtune = -g -O0

# Makefile rules
main:
	$(CC) $(CFLAGS) main.c -o main.exe

vtune:
	$(CC) $(CFLAGS_vtune) main.c -o main_vtune.exe
# End of makefile