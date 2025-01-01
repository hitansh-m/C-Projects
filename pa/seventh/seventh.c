#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(char *str)
{
    char *words[256]; 
    int counter = 0;  
    int index = 0;
    char *word = strtok(str, " \t\n");
    while (word != NULL)
    {
        words[counter] = word; 
        counter++;
        word = strtok(NULL, " \t\n"); 
    }
    char *result = (char *)malloc(counter+1); 
    for (int i = 0; i < counter; i++) {
        int len = strlen(words[i]);  
        result[index++] = words[i][len - 1];  
    }
    result[index] = '\0';
    printf("%s", result);
    free(result);
}

int main(int argc, char *argv[])
{
    char str[256];
    for (int i = 1; i < argc; i++)
    {
        strcpy(str, argv[i]);
        split(str);
    }
    return 0;
}