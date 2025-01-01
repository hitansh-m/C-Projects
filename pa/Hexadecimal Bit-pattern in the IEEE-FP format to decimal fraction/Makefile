# Simple Makefile without variables

# The default rule to build the program
all: fifth  # Replace 'fifth' with the name of the program for each directory

# Rule to build the 'fifth' executable (change the name accordingly)

fifth: fifth.c  
	gcc -g -Wall -Werror -fsanitize=address -o fifth fifth.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f fifth  # Replace 'fifth' with the name of the executable for each directory
