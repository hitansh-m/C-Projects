#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void check(char *ch)
{
    int index = 0;
    char *token = strtok(ch, " ");
    char *result = (char *)malloc(1);
    result[0] = '\0';
    char *result2 = (char *)malloc(1);
    result2[0] = '\0';
    while (token != NULL)
    {
        char firstLet = token[0];
        int chLen = strlen(token);
        if (isVowel(firstLet))
        {
            result = (char *)realloc(result, strlen(result) + strlen(token) + 5);
            strcat(result, token);
            strcat(result, "yay");
        }
        else
        {
            for (int i = 1; i < chLen; i++)
            {
                if (isVowel(token[i]))
                {
                    index = i;
                    break;
                }
            }
            char temp[index + 1];
            char temp2[chLen - index + 1];
            strncpy(temp, token, index);
            temp[index] = '\0';
            strncpy(temp2, token + index, chLen - index);
            temp2[chLen - index] = '\0';
            result2 = (char *)realloc(result2, strlen(temp) + strlen(temp2) + 3);
            strcpy(result2, temp2);
            strcat(result2, temp);
            strcat(result2, "ay");
            result = (char *)realloc(result, strlen(result) + strlen(result2) + 2);
            strcat(result, result2);
        }
        strcat(result, " ");
        token = strtok(NULL, " ");
    }
    printf("%s", result);
    free(result);
    free(result2);
}

int main(int argc, char *argv[])
{
    char str[256];
    for (int i = 1; i < argc; i++)
    {
        strcpy(str, argv[i]);
        check(str);
    }
    return 0;
}
