# Simple Makefile without variables

# The default rule to build the program
all: fourth  # Replace 'fourth' with the name of the program for each directory

# Rule to build the 'fourth' executable (change the name accordingly)

fourth: fourth.c  
	gcc -g -Wall -Werror -fsanitize=address -o fourth fourth.c -lm



# Clean rule to remove object files and the executable
clean:
	rm -f fourth  # Replace 'fourth' with the name of the executable for each directory
