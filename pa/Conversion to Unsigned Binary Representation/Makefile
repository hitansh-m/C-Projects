# Simple Makefile without variables

# The default rule to build the program
all: first  # Replace 'first' with the name of the program for each directory

# Rule to build the 'first' executable (change the name accordingly)

first: first.c  
	gcc -g -Wall -Werror -fsanitize=address -o first first.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f first  # Replace 'first' with the name of the executable for each directory
