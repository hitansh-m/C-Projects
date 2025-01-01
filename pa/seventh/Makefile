# Simple Makefile without variables

# The default rule to build the program
all: seventh  # Replace 'seventh' with the name of the program for each directory

# Rule to build the 'seventh' executable (change the name accordingly)

seventh: seventh.c  
	gcc -g -Wall -Werror -fsanitize=address -o seventh seventh.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f seventh  # Replace 'seventh' with the name of the executable for each directory
