# Simple Makefile without variables

# The default rule to build the program
all: ninth  # Replace 'first' with the name of the program for each directory

# Rule to build the 'first' executable (change the name accordingly)

ninth: ninth.c  
	gcc -g -Wall -Werror -fsanitize=address -o ninth ninth.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f ninth  # Replace 'first' with the name of the executable for each directory
