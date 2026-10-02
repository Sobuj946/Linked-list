#include<stdio.h>
#include<math.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node *start=NULL;
void insert_begining()
{
    int value;
    printf("Enter the value:");
    scanf("%d",&value);
    struct Node*temp,*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=start;
    start=newnode;
}
void insert_at_position()
{
    int value,pos;
    printf("Enter value and position of the linked list:");
    scanf("%d%d",&value,&pos);
    struct Node*temp,*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    temp=start;
    if(pos==0)
    {
        insert_begining();
        return;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp=newnode;
    }
}
void end_postion()
{
    int value;
    printf("Enter the value add last postion:");
    scanf("%d",&value);
    struct Node *newnode,*temp;
    newnode->data=value;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next = newnode;
    }
}
int main(){

    int n;
    printf("Enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct Node*newnode,*temp;
        int value;
        scanf("%d",&value);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=value;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }

    }
    return 0;
}