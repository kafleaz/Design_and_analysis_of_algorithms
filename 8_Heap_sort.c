// To create a new heap array based on heap sort algorithm (max heap)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main() 
{
   int heap[500000], no, i, j, c, root, temp;
   int randNum;
   double time;
   clock_t start, end;
   printf("\n Enter no of elements :");
   scanf("%d", &no);
   start = clock();
   for (i = 0; i < no; i++) 
   {
       randNum = (rand() % 10000);
       heap[i] = randNum;
   }

   for (i = 1; i < no; i++) 
   {
       c = i;
       do {
           root = (c - 1) / 2;
           if (heap[root] < heap[c]) 
           {
               temp = heap[root];
               heap[root] = heap[c];
               heap[c] = temp;
           }
            c = root;
       } while (c != 0);
   }

   printf("\n Heap array: ");
   for (i = 0; i < no; i++) 
   {
       printf("%d\t", heap[i]);
   }

   for (j = no - 1; j >= 0; j--) 
   {
       temp = heap[0];
       heap[0] = heap[j];
       heap[j] = temp; /* swap max element with rightmost leaf element */
       root = 0;
       do 
       {
           c = 2 * root + 1; /* left node of root element */
           if ((heap[c] < heap[c + 1]) && c < j - 1) 
           {
               c++;
           }
           if (heap[root] < heap[c] && c < j) 
           { /* again rearrange to max heap array */
               temp = heap[root];
               heap[root] = heap[c];
               heap[c] = temp;
           }
            root = c;
       } while (c < j);
   }

   printf("\n The sorted array is: ");
   for (i = 0; i < no; i++) 
   {
       printf("\t %d", heap[i]);
   }
   end = clock();
   time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
   printf("\n Time=%lf milliseconds", time);
}
