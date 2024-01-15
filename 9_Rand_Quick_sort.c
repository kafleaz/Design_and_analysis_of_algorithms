#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int partition(int a[], int first, int last);
int randpartition(int a[], int first, int last) 
{
  int k, temp;
  k = (rand()%(last - first)) + first;
  //swapping
  temp=a[first];
  a[first]=a[k];
  a[k]=temp;
  return partition(a, first, last);
}

int partition(int a[], int first, int last) 
{
  int i, j, pivot, temp;
  if(first<last) {
    pivot=first;
    i=first;
    j=last;
    while(i<j) 
    {
      while(a[i]<=a[pivot]&&i<last)
        i++;
      while(a[j]>a[pivot])
        j--;
      if(i<j) 
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;
    return j;
  }
  return 0;
}

void randquicksort(int a[], int first, int last) {
  int p;
  if (first<last) {
    p=randpartition(a, first, last);
    randquicksort(a, first,p-1);
    randquicksort(a,p+1,last);
  }
}

int main() {
  int a[50000],n,i,randNum;
  double time;
  clock_t start, end;
  printf("Enter the total input size:");
  scanf("%d",&n);
  start = clock();
  for (i=0;i<n;i++) 
  {
    randNum=(rand()%10000);
    a[i]=randNum;
    printf("%d\t", a[i]);
  }
  //quick sort
  randquicksort(a,0,n-1);
  //printing sorted List
  printf("\n Sorted list:\n");
  for(i=0;i<n;i++)
    printf("%d \t", a[i]);
  //end clock
  end = clock();
  time = ((double) (end-start)*1000)/CLOCKS_PER_SEC;
  printf("\n Time Taken = %lf milliseconds", time);
  return 0;
}
