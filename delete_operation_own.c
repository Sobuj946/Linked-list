#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
struct Node*start=NULL;
void delete_begining()
{
    if(start==NULL)
    {
        printf("List is empty\n");
    return ;
    }
    struct Node *temp=start;
    start->next=start;
}
void delete_at_midle_any_index()
{
    
}
int main(){

    int n;
    printf("Enter the number of element:");
    scanf("%d",&n);
    struct Node*newnode,*temp;
    start=NULL;
    for(int i=0;i<n;i++)
    {
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
    delete_begining();

    return 0;
}