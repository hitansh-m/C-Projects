# Simple Makefile without variables

# The default rule to build the program
all: third  # Replace 'third' with the name of the program for each directory

# Rule to build the 'third' executable (change the name accordingly)

third: third.c  
	gcc -g -Wall -Werror -fsanitize=address -o third third.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f third  # Replace 'first' with the name of the executable for each directory
