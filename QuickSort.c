#include<stdio.h>
#include<stdlib.h>
void quicksort(int [],int,int);
int partition(int [],int,int);

int main()
{
    int a[10];
    int i,n = 5;
    for(i = 0;i < n;i++)
        a[i] = rand()%100;
        for(i = 0;i < 5;i++)
        printf("% 2d",a[i]);
    quicksort(a,0,n - 1);
    printf("\n");
    for(i = 0;i < 5;i++)
        printf("% 2d",a[i]);
}

void quicksort(int a[],int low,int high)
{
    if(low < high)
    {  
        int j;
        j = partition(a,low,high);
        quicksort(a,low,j - 1);
        quicksort(a,j+ 1,high);
    }
    
}
int partition(int a[],int low,int high)
{
    int pivot;
    pivot = a[low];
    int i,j,t;
    i = low ;
    j = high;
    while(i < j)
    {
        while( a[i] <= pivot)
               i++;
        while(a[j] > pivot)
               j--;
        if(i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

