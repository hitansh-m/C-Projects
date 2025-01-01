# Simple Makefile without variables

# The default rule to build the program
all: sixth  # Replace 'sixth' with the name of the program for each directory

# Rule to build the 'sixth' executable (change the name accordingly)

sixth: sixth.c  
	gcc -g -Wall -Werror -fsanitize=address -o sixth sixth.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f sixth  # Replace 'first' with the name of the executable for each directory
