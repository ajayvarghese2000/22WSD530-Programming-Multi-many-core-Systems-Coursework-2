# The compiler to use
CC = gcc

# The compiler flags
CFLAGS = -fopenmp

# Makefile rules
fast:
	$(CC) $(CFLAGS) main_fast.c -o ./bin/fast.exe
    # Run the program
	./bin/fast.exe

original:
	$(CC) $(CFLAGS) main.c -o ./bin/original.exe
	# Run the program
	./bin/original.exe

# End of makefile