#include<stdio.h>

int minimum(int,int);
int sort(int);
 int a[10] = { 15,28,17,12,18,9,6};
int main()
{
    int elem;
    int n = 7,i;
   
    sort(n);
     
    for(i = 0;i < 7;i++) 
        printf("%3d",a[i]);
}

int sort(int n)
{
    int min,i,t,j,pass;
    for(i = 0; i < n ;i++)
    {
        min = minimum(i,n);
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}
int minimum(int low,int n)
{  
    int i,min;
    min = low;
    for( i = low ;i < n;i++)
    {
        if(a[i] < a[min])
           min = i;
    } 
    return min;
}

