#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int low,int mid,int high)
{
    int i ,j,k;
    i = low;
    j = mid + 1;
    k = 0;
    int *temp = (int *) malloc (sizeof(int)*(high - low + 1));
    while(i <= mid&&j<= high)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(j <= high)  
          temp[k++] = a[j++];
    while(i <= mid)
          temp[k++] = a[i++];
    for(i= low,k = 0;k < (high - low + 1);i++,k++)
        a[i] = temp[k];
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid + 1,high);
        merge(a,low,mid,high);
    }
}


int main()
{
    int size = 6;
    int i;
    int a[10] = {1,4,5,7,3,2};
    mergesort(a,0,size - 1);
    for(i =0;i <6;i++) 
        printf("%2d",a[i]);
    
}
