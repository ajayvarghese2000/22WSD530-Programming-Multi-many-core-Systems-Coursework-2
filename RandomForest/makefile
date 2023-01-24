# The compiler to use
CC = gcc

# The compiler flags
CFLAGS = -fopenmp

# Makefile rules
all:
	$(CC) main.c -lm -o ./bin/original.exe
	$(CC) $(CFLAGS) main_fast.c -lm -o ./bin/fast.exe
fast:
	$(CC) $(CFLAGS) main_fast.c -lm -o ./bin/fast.exe
	@for i in {1..1}; do ./bin/fast.exe; done

original:
	$(CC) main.c -lm -o ./bin/original.exe
	@for i in {1..1}; do ./bin/original.exe; done
run_all:
	@for i in {1..100}; do ./bin/original.exe; done
	@for i in {1..100}; do ./bin/fast.exe; done

# End of makefile