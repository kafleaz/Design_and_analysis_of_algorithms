// WAP to perform the empirical analysis of iterative algorithm for linear search.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int LinearSearch(int *arr, int n,int key);
int main()
{
    clock_t start, end;
    double time;
    int arr[500000],n,key, num;
    printf("-----Linear Searching--------\n");
    printf("\nEnter size of array\n");
    scanf("%d",&n);
    printf("%d numbers\n",n);
    for (int i = 0; i < n; i++)
    {
        num = (rand()%10000);
        arr[i] = num;
    }
    printf("Enter the key\n");
    scanf("%d",&key);
    start = clock();
    int ans = LinearSearch(arr,n,key);
    if(ans!=-1)
    {
        printf("\n%d is in %d index.\n",key,ans);
    }
    else
    {
        printf("\nNot Found\n");
    }
    end = clock();
    time=((double)(end-start)*10000) / CLOCKS_PER_SEC;
    printf("Time=%lf microseconds", time);
}

int LinearSearch(int *arr, int n,int key)
{
    for(int i=0;i<n; i++)
    {
        if(arr[i]== key)
        {
            return i+1;
        }
    }
    return -1;
}
