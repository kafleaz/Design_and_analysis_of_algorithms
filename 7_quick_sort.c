#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int first, int last) 
{
  int i, j, pivot, temp;
  if (first < last) 
  {
    pivot = first;
    i = first;
    j = last;
    while (i < j) 
    {
      while (a[i] <= a[pivot] && i < last)
        i++;
      while (a[j] > a[pivot])
        j--;
      if (i < j) 
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    return j;
  }
}

void quicksort(int a[], int first, int last) 
{
  int p;
  if (first < last) 
  {
    p = partition(a, first, last);
    quicksort(a, first, p - 1);
    quicksort(a, p + 1, last);
  }
}

int main() 
{
  int a[500000], n, i, randNum;
  double time;
  clock_t start, end;
  printf("Enter the total input size:");
  scanf("%d", &n);
  start = clock();
  for (i = 0; i < n; i++) 
  {
    randNum = rand() % 10000;
    a[i] = randNum;
    printf("%d\t", a[i]);
  }
  quicksort(a, 0, n - 1);
  printf("\nSorted list:");
  for (i = 0; i < n; i++) 
  {
    printf("%d \t", a[i]);
  }
  end = clock();
  time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
  printf("\nTime=%lf millseconds", time);
  return 0;
}
