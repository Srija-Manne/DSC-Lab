#include<stdio.h>
int binarysearch(int [],int,int);
int main()
{
    int a[10] = {1,2,3,4,5,6};
    int res,key = 5;
    res = binarysearch(a,6,key);
    if(res != -1)
       printf("%d is found",a[res]);
}
int binarysearch(int a[],int size,int key)
{
    int low = 0;
    int mid,high = size - 1;
    while(low <= high)
    {   
        mid = (low+high)/2;
        if(key == a[mid])
           return mid;
        else if(key < a[mid])
           high = mid - 1;
        else if(key > a[mid])
           low = mid + 1;
    }
    return -1;
}
