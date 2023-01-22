# The compiler to use
CC = gcc

# The compiler flags
CFLAGS = -fopenmp

# Makefile rules
fast:
	$(CC) $(CFLAGS) main_fast.c -o ./bin/fast.exe
	@for i in {1..1}; do ./bin/fast.exe; done

slow:
	$(CC) $(CFLAGS) main_slow.c -o ./bin/slow.exe
	@for i in {1..1}; do ./bin/slow.exe; done

original:
	$(CC) main.c -o ./bin/original.exe
	@for i in {1..1}; do ./bin/original.exe; done

# End of makefile