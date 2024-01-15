#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void merge(int a[], int i1, int j1, int i2, int j2);
void mergesort(int a[], int i, int j)
{
    int mid;
    if(i<j)
    {
        mid =(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}
void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[10000];
    int i,j,k;
    i=i1;
    j=i2,
    k=0;
    while (i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while (i<=j1)
    {
        temp[k++]=a[i++];
    }
    while (j<=j2)
    {
        temp[k++]=a[j++];
    }
    for (i=i1,j=0;i<=j2;i++,j++)
    {
        a[i]=temp[j];
    }   
}
int main()
{
    int a[500000],n,i,randNum;
    double time;
    clock_t start,end;
    printf("\nEnter the total input size:");
    scanf("%d",&n);
    printf("\narray elements are:\n");
    start=clock();
    for (i=0;i<n;i++)
    {
        randNum=(rand()%10000);
        a[i]=randNum;
        printf("%d\t",a[i]);
    }
    mergesort(a,0,n-1);
    printf("Sorted array is :\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    end=clock();
    time=((double)(end-start)*1000)/CLOCKS_PER_SEC;
    printf("\nTime=%lf milliseconds",time);
    return 0;
}