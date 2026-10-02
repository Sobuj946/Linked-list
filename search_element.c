#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
    int data;
    struct Node*next;
};

int main(){
    int n;
    int value;
    printf("Enter the number:");
    scanf("%d",&n);
    struct Node*temp,*newnode,*start;
    start = NULL;
    for(int i=0;i<n;i++)
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
    int search_value;
    printf("Enter the search value:");
    scanf("%d",&search_value);
    temp=start;
    bool f=false;
    while(temp!=NULL)
    {
       if(search_value==temp->data)
       {
        f=true;
       break;
       
       }
       
        temp=temp->next;
    }
    if(f)
    {
        printf("The searching value is valid\n");

    }
    else
       {
        printf("The searching value is not  valid\n");
       }
    
    return 0;
}