#include<stdio.h>
#include <stdlib.h>
#include<math.h>
struct Node{
    int data;
    struct Node * next;
};
int main(){
    struct Node *start=NULL;
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    first->data='A';
    second->data='B';
    third->data='C';
    first->next=second;
    second->next=third;
    third->next=NULL;
    start=first;
    struct Node *temp=start;
    while (temp!=NULL)
    {
        printf("%c\n",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
    return 0;
}