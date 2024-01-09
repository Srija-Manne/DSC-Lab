
#include <stdio.h>

void insertion(int n,int a[] )
{ 
    int key,i;
    key = a[n];
    for(i = n - 1;i >= 0;i--)
    {
        if(a[i] > key)
        {
            a[i + 1] = a[i];
            a[i] = key;
        }
    }
}

int main()
{   
    int i;
    int a[4] = {4,3,6,5};
    for(i = 0;i < 4;i ++)
    {
      insertion(i,a);
    }
    for(i = 0;i<4;i++)
    printf("%2d",a[i]);

}

