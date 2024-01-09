#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct linkedlist
{
    int data;
    struct linkedlist *pleft;
    struct linkedlist *pright;
};
typedef struct linkedlist list;
void inorder(list *);
list * create()
{
    int x;
    list *newnode;
    newnode = (list *)malloc(sizeof(list));
    
    printf("enter x value:");
    scanf("%d",&x);
    if(x == -1)
       return 0;
    newnode -> data = x;
    newnode -> pleft = create();
    printf("right root is:");
    newnode -> pright = create();
    return newnode;
    
}
int main()
{
  list *root,*temp;
  root = create();
  temp = root;
  inorder(root);
  
}
void inorder(list *root)
{
  while(root != NULL)
  {   
      inorder( root -> pleft);
      printf("%d",root -> data);
      inorder( root -> pright);
  }
}
