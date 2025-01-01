# Simple Makefile without variables

# The default rule to build the program
all: second  # Replace 'second' with the name of the program for each directory

# Rule to build the 'second' executable (change the name accordingly)

second: second.c  
	gcc -g -Wall -Werror -fsanitize=address -o second second.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f second  # Replace 'first' with the name of the executable for each directory
