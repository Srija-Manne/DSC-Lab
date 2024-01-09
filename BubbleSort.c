#include <stdio.h>

int main()
{
    int i,n,a[10],j,t;
    
    printf("ENTER n:");
    scanf("%d",&n);
    
    printf(" enetr elemets:");
    for(i=0;i<n;i++)
    {  
       scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {   for(j=0;j<n-1;j++)
        {
            if(a[j+1]<a[j])
          {  t =a[j+1];
             a[j+1]=a[j];
             a[j]=t;
          }
        }
    }
    for(i=0;i<n;i++)
    printf(" %d",a[i]);
}

