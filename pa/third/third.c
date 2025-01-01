#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int val;
    int key;
} Node;

static Node **table = NULL;
static int size = 1000;
static int count;
int hashFunc(int x)
{
    if (x<0){
        x = x*-1;
    }
    return (x % size);
}

void search(int key)
{
    int index = hashFunc(key);
    Node *ptr = *(table + index);
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            printf("present\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("absent\n");
}

void insert(int key, int val)
{

    int index = hashFunc(key);
    Node *item = malloc(sizeof(struct Node));
    item->key = key;
    item->val = val;
    item->next = NULL;

    Node *ptr = *(table + index);
    if (ptr == NULL)
    {
        table[index] = item;
        printf("inserted\n");
        count++;
        return;
    }
    else if (ptr->key == key)
    {
        printf("duplicate\n");
        free(item);
        return;
    }
    while (ptr->next != NULL)
    {
        if (ptr->key == key)
        {
            printf("duplicate\n");
            free(item);
            return;
        }
        ptr = ptr->next;
    }
    ptr->next = item;
    count++;
    printf("inserted\n");
}

void freeT(){
    for (int i = 0; i<size; i++){
        Node *ptr = table[i];
        while (ptr != NULL){
            Node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    free(table);
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("error\n");
        return 0;
    }
    table = calloc(size, sizeof(Node *));
    char ch;
    int x;
    while (fscanf(f, "%c\t%d\n", &ch, &x) == 2)
    {
        if (ch == 'i')
        {
            insert(x, x);
        }
        else if (ch == 's')
        {
            search(x);
        }
    }
    fclose(f);
    freeT();
}
