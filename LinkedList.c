#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct nodelist
{
    int data;
    struct nodelist *link;
    
};
typedef struct nodelist node;

int main()
{
    int choice;
    node *head,*newnode,*temp;
    head =0;
    printf("enter choice:");
    scanf("%d",&choice);
    while(choice)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("enter elem");
        scanf("%d",&newnode -> data);
        newnode -> link =0;
        if(head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp -> link = newnode;
            temp = newnode;
        }
    }
    temp = head;
    while(temp!=0)
    {
       printf("%d",temp -> data);
       temp = temp -> link;
    }
}
