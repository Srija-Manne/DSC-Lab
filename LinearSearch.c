/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int fun(int a[10],int k,int i);
int s=-1,n;

int main()
{
    int k,a[10],t,i;
    printf("enter n,k:");
    scanf("%d %d",&n,&k);
    i=n;
    printf("enter elememts");
    for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
    } 
    t=fun(a,k,i);
    if(t==-1)
    {
        printf("unsuccesful search");
    }
    else
    printf("succesful search");
    
}
int fun(int a[10],int k,int i)
{   
    if(k==a[i])
       s=i;
    if(i==-1)
    return 0;
    else
    fun(a,k,i-1);
    return s;
    
}

