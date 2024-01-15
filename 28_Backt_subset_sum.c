#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSubset(int A[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void subsetSum(int S[], int T[], int S_size, int T_size, int sum, int ite, int const target_sum) {
    if(target_sum == sum) {
        printSubset(T, T_size);
        if(ite + 1 < S_size && sum - S[ite] + S[ite+1] <= target_sum) {
            subsetSum(S, T, S_size, T_size-1, sum - S[ite], ite + 1, target_sum);
        }
        return;
    }
    else {
        if(ite < S_size && sum + S[ite] <= target_sum) {
            for(int i = ite; i < S_size; i++) {
                T[T_size] = S[i];
                if(sum + S[i] <= target_sum) {
                    subsetSum(S, T, S_size, T_size + 1, sum + S[i], i + 1, target_sum);
                }
            }
        }
    }
}

void generateSubsets(int S[], int size, int target_sum) {
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    subsetSum(S, tuplet_vector, size, 0, 0, 0, target_sum);
    free(tuplet_vector);
}

int main() {
    int weights[1000];
    int i, n, sum;
    double time;
    clock_t start, end;

    printf("Enter number of items:");
    scanf("%d", &n);

    printf("Enter target sum:");
    scanf("%d", &sum);

    start = clock();
    for(i = 0; i < n; i++) {
        weights[i] = rand() % 1000;
        printf("Item :%d \n", weights[i]);
    }
    printf("Subsets with sum %d are:\n", sum);
    generateSubsets(weights, n, sum);
    end = clock();

    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf milliseconds\n", time);

    return 0;
}