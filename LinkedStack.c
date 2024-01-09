#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct nodelist
{
    int data;
    struct nodelist *link;
};
typedef struct nodelist node;

struct stacklinkedlist
{
    node *tos;
};
typedef struct stacklinkedlist stack;

node * createnewnode();
stack * create();
bool push(stack *,int);
void display(stack *);

int main()
{  
   int elem,choice;
   bool res;
   node *ptr1;
   stack *ptr2;
   ptr2 = create();
   while(1)
   {   
       printf("enter choice 1.push 2.exit 3.display:");
       scanf("%d",&choice);
       
       switch(choice)
       {
           case 1:
                   printf("enter element:\n");
                   scanf("%d",&elem);
                   res = push(ptr2,elem);
                   break;
           case 2:
                   return 0;
                   break;
           case 3:
                   display(ptr2);
                   break;
           
       }
       if(res == false)
        {
            printf("memory is not allocatef");
            return 0;
        }
       
   }
}

node * createnewnode(int elem)
{
    node *pnew = NULL;
    pnew = (node *) malloc (sizeof(node));
       
    pnew -> data = elem;
    pnew -> link = 0;
    
    return pnew;
    
}

stack * create()
{
    stack * pnew;
    pnew = (stack *) malloc (sizeof(stack));
    pnew -> tos = 0;
    return pnew;
}

bool push(stack *pt2,int elem)
{
    node *pnew = NULL;
    
    pnew = createnewnode(elem);
    if(pnew == NULL)
       return false;
       
    pnew -> link = pt2 -> tos;
    pt2 -> tos = pnew;
    return true;
    
}
void display(stack *pt2)
{
    node *pthis;
    pthis = pt2 -> tos;
    while(pthis != 0 )
    {
        printf("|%d|%p|\n",pthis -> data,pthis -> link);
        pthis = pthis -> link;
    }
}

