#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;

} *Node;

struct Node *insert(struct Node *cur, int x)
{
    if (cur != NULL && cur->data == x)
    {
        return cur;
    }
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    if (cur == NULL || x<cur->data)
    {
        temp->next = cur;
        return temp;
    }
    struct Node* ptr = cur;   
    while (ptr->next != NULL && ptr->next->data < x) {
        ptr = ptr->next; 
    }
    if (ptr->next != NULL && ptr->next->data == x) {
        free(temp); 
        return cur;
    }
    temp->next = ptr->next;
    ptr->next = temp;

    return cur;
}

struct Node *delete(struct Node *cur, int x)
{
    if (cur == NULL)
    {
        return 0;
    }

    struct Node *ptr = cur;
    if (x == ptr->data)
    {
        cur = cur->next;
        free(ptr);
        return cur; 
    }

   struct Node *prev = NULL;

    while (ptr != NULL && ptr->data != x)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
        return cur;

    prev->next = ptr->next;
    free(ptr);

    return cur;
}

int countNodes(struct Node* cur){
    int count = 0;
    if (cur == NULL){
        return 0;
    }
    while (cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

void PrintList(struct Node* cur){
    if (cur == NULL){
        return;
    }
    struct Node* ptr = cur;
    while (ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("error\n");
        return 1;
    }
    
    Node head = NULL;
    char ch;
    int x;
    while (fscanf(f, "%c\t%d\n", &ch, &x) == 2)
    {
        if (ch == 'i')
        {
            head = insert(head, x);
        }
        else if (ch == 'd')
        {
            head = delete (head, x);
        }
    }
    fclose(f);
    
    int total = countNodes(head);
    printf("%d\n", total);
    PrintList(head);
    
    Node temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
