#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n, i, j, a[500000], randnum, temp;
    double time;
    clock_t start, end ;
    printf("enter the number of elements");
    scanf("%d", &n);
    start = clock();
    for (i = 0; i < n; i++) 
    {
        randnum = (rand() % 10000);
        a[i] = randnum;
        printf("%d\t", a[i]);
    }
    for (i = 1; i < n - 1; i++) 
    {
        temp = a[i];
        j = i - 1;
        while (temp <= a[j] && (j >= 0)) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;    
    }
    printf("\nsorted list:");
    for (i = 0; i < n; i++) 
    {
    printf("%d\t", a[i]);
    }

  end = clock();
  time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
  printf("\ntime=%lf milli seconds", time);
  return 0;
}
