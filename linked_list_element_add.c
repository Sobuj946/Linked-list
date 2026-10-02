#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main(){
    int n;
    printf("Enter number of element :");
    scanf("%d",&n);
    int value;
    
        struct Node*temp,*newnode,*start;
        start=NULL;
    for(int i=1;i<=n;i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&value);
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
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    return 0;
}