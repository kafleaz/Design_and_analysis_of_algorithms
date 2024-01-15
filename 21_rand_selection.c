#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

int randomized_partition(int a[], int low, int high) {
    // Choose a random pivot index within the subarray
    int pivot_index = low + rand() % (high - low + 1);
    // Swap the pivot with the last element
    int temp = a[pivot_index];
    a[pivot_index] = a[high];
    a[high] = temp;
    // Partition around the pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= a[high]) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // Place the pivot in its correct position
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void randomized_selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i; // Find the i-th smallest element
        int pos = randomized_partition(a, k, n - 1);
        // Ensure the pivot is at its correct position (i-th smallest)
        if (pos != k) {
            int temp = a[k];
            a[k] = a[pos];
            a[pos] = temp;
        }
    }
}

int main() {
int i, j, n, a[500000], randNum, temp, pos;
    double time;
    clock_t start, end;
    // Get input size from the user
    printf("Enter the total input size:");
    scanf("%d", &n);
    // Seed the random number generator
    //srand(time(NULL));
    // Generate random numbers and print the unsorted array
    start = clock();
    for (i = 0; i < n; i++) {
        randNum = (rand() % 10000);
        a[i] = randNum;
        printf("%d\t", a[i]);
    }
    // Perform randomized selection sort
    randomized_selection_sort(a, n);
    // Print the sorted array
    printf("\nThe sorted list:\nThe numbers:");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    // Calculate and print the execution time
    end = clock();
    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime=%lf milliseconds", time);

    return 0;
}

