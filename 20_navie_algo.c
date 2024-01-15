#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, a[500000], randNum, temp, min_index;
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

    // Naive Selection Sort implementation
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        // Swap the minimum element with the current element
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
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
