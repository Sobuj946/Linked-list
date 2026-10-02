#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start;
void insertfirst()
{
    int value_add;
    scanf("%d", &value_add);
    struct Node *temp, *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value_add;
    newnode->next = start;
    start = newnode;
}
void insert_at_pos()
{
    int n, value;
    printf("Enter position & value:");
    scanf("%d%d", &n, &value);
    struct Node *temp, *newnode;
    if (n == 0)
    {
        insertfirst();
        return;
    }

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    temp = start;
    for (int i = 0; i < n - 1; i++)
    {
        if (temp == NULL)
        {
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp = newnode;
}
void end_add()
{
    printf("Enter the value last position add:");
    int n;
    scanf("%d", &n);
    struct Node *newnode, *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (start == NULL)
    {
        start = newnode;
    }
    temp = start;
    newnode->data = n;
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void print()
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{

    int n;
    scanf("%d", &n);
    struct Node *temp, *newnode;
    for (int i = 1; i <= n; i++)
    {
        int value;
        scanf("%d", &value);
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    printf("First index value add:");
    insertfirst();
    insert_at_pos();
    end_add();
    print();

    return 0;
}