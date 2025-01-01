#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int key;
    int height; 
} Node;

static Node *root = NULL;

int height(Node *cur, int key)
{
    if (cur == NULL)
    {
        return -1;
    }
    int d = 0;
    if ((cur->key == key) || (d = height(cur->left, key)) >= 0 || (d = height(cur->right,key)) >= 0 ){
    return d + 1;
    }
    return d;
}

Node *insertN(Node *cur, int key, int *isDuplicate)
{
    if (cur == NULL)
    {
        Node *item = malloc(sizeof(Node));
        item->key = key;
        item->left = NULL;
        item->right = NULL;
        return item;
    } 
    else if (key == cur->key)
    {
        *isDuplicate = 1;
        return cur;
    }
    if (key < cur->key)
    {
        cur->left = insertN(cur->left, key, isDuplicate);
    }
    else if (key > cur->key)
    {
        cur->right = insertN(cur->right, key, isDuplicate);
    }

    return cur;
}
void insert(int key)
{
    int isDuplicate = 0;
    root = insertN(root, key, &isDuplicate);

    if (isDuplicate)
    {
        printf("duplicate\n");
    }
    else
    {
        int h = height(root, key);
        printf("inserted %d\n", h);
    }
}

Node* findMin(Node *cur) {
    while (cur && cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}

Node *deleteN(Node *cur, int key) {
    Node *temp;
    
    if (cur == NULL) {
        printf("fail\n");
        return NULL;    
    }

    if (key < cur->key) {
        cur->left = deleteN(cur->left, key);
    } else if (key > cur->key) {
        cur->right = deleteN(cur->right, key);
    } else {
        if (cur->left == NULL) {
            temp = cur->right; 
            free(cur);
            printf("success\n");
            return temp; 
        } else if (cur->right == NULL) {
            temp = cur->left; 
            free(cur);
            printf("success\n");
            return temp; 
        } else {
            temp = findMin(cur->right);
            cur->key = temp->key; 
            cur->right = deleteN(cur->right, temp->key); 
        }
    }
    return cur;
}
void delete(int key){
    root = deleteN(root, key);
}
void search(int key)
{
    Node *ptr = root;
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            int h = height(root, key);
            printf("present %d\n", h);
            return;
        }
        if (key < ptr->key) 
            ptr = ptr->left;
        else
        {
            ptr = ptr->right;
        }
    }
    printf("absent\n");
}

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("error\n");
        return 0;
    }
    char ch;
    int x;
    while (fscanf(f, "%c\t%d\n", &ch, &x) == 2)
    {
        if (ch == 'i')
        {
            insert(x);
        }
        else if (ch == 'd')
        {
            delete(x);
        } 
        else if (ch == 's')
        {
            search(x);
        }
    }
    fclose(f);
    return 0;
}