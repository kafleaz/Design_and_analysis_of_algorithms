//selection sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int smallest(int a[], int k, int n, int pos) {
   int small, j;
   small = a[k];
   for (j = k + 1; j < n - 1; j++) {
       if (small > a[j]) {
           small = a[j];
           pos = j;
       }
   }
   return pos;
}

int main() {
   int i, j, n, a[500000], randNum, temp, pos;
   double time;
   clock_t start, end;

   printf("Enter the total input size:");
   scanf("%d", &n);

   start = clock();
   for (i = 0; i < n; i++) {
       randNum = (rand() % 10000);
       a[i] = randNum;
       printf("%d\t", a[i]);
   }

   for (i = 1; i < n - 1; i++) {
       pos = smallest(a, i, n, pos);
       temp = a[i];
       a[i] = a[pos];
       a[pos] = temp;
   }

   printf("\nThe sorted list:\nThe numbers:");
   for (i = 0; i < n; i++) {
       printf("%d\t", a[i]);
   }

   end = clock();
   time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
   printf("\nTime=%lf milliseconds", time);

   return 0;
}
