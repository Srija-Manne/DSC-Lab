#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stackADT
{
    int tos;
    int *list;
    int capacity;
};
typedef struct stackADT stack;

bool push(stack *,int);
void peep(stack *);
void display(stack *);
bool pop(stack *,int *);
stack * create(int cap)
{
    stack *pnew;
    pnew  =   (stack *) malloc (sizeof(stack));
    pnew -> tos = -1;
    pnew -> capacity = cap;
    pnew -> list =  (int *) malloc (sizeof(int));
    return pnew;
}

int main()
{
    stack *ptr;
    bool res;
    int elem,ch,cap = 5;
    ptr = create(cap);
    while(1)
    {
        printf("Enter choice 1.push 2.peep 3.display:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   printf("Enter elem:");
                   scanf("%d",&elem);
                   push(ptr,elem);
                   break;
            case 2:
                   peep(ptr);
                   break;
            case 3:
                   display(ptr);
                   break;
            case 4:
                   res = pop(ptr,&elem);
                   if(res == false)
                      printf("stack is empty:");
                else
                     printf("%d is succesfully deleted:",elem);
                   
        }
    }
}
bool push(stack *pthis,int elem)
{   
    if(pthis -> tos == pthis -> capacity - 1)
       return false;
    pthis -> tos++;
    pthis -> list[pthis -> tos] = elem;
    return true;
}
void peep(stack *pthis)
{
    printf("\nlist[%d] = %d",pthis -> tos,pthis -> list[pthis -> tos]);
}
void display(stack *pthis)
{
    int i;
    for(i = pthis -> tos;i >= 0;i--)
        printf("\n list[%d] = %d",i,pthis -> list[i]);
}
bool pop(stack *pthis,int *pdel)
{  
    if(pthis -> tos == -1)
       return false;
    *pdel = pthis -> list[pthis -> tos];
    pthis -> tos--;
    return true;
}
