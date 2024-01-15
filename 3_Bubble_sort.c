#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <conio.h>

int main()
{    
    int i,j,n,a[500000], randNum, temp;
    double time;
    clock_t start,end;
    printf("Enter the total input size:");
    scanf("%d",&n);

    start=clock();
    for (i=0;i<n;i++) 
    {
        randNum=(rand() % 10000);
        a[i]=randNum;
        printf("%d\t", a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

            }
       }                        
    }
    printf("\nThe sorted list:");
    printf("\nThe numbers:");

    for (i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    end=clock();
    time=((double) (end-start)*1000)/CLOCKS_PER_SEC;
    printf("\n Time %lf millseconds", time);
    return 0;

}