#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on profit (descending order)
int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

int main() {
    int i, n, max_deadline = 0;
    struct Job jobs[50000];  // Adjust array size if needed

    printf("Enter the total number of jobs: ");
    scanf("%d", &n);

    srand(time(NULL));  // Seed the random number generator

    // Generate random job details
    for (i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].deadline = rand() % 10000;  // Random deadline between 1 and n
        jobs[i].profit = rand() % 10000;     // Random profit between 0 and 999
        max_deadline = (jobs[i].deadline > max_deadline) ? jobs[i].deadline : max_deadline;
    }

    // Sort jobs based on profit in descending order
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    int result[max_deadline];
    for (i = 0; i < max_deadline; i++) {
        result[i] = -1;  // Initialize with -1 to indicate no job scheduled
    }

    clock_t start = clock();  // Start time measurement

    // Naive algorithm implementation
    for (i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;  // Schedule the job in the first available slot
                break;
            }
        }
    }


    printf("\nSelected jobs (in order of execution):\n");
    for (i = 0; i < max_deadline; i++) {
        if (result[i] != -1) {
            printf("Job %d (deadline %d, profit %d)\n", result[i], jobs[result[i]].deadline, jobs[result[i]].profit);
        }
    }

    clock_t end = clock();  // End time measurement
    double time_taken = ((double)(end - start)*1000) / CLOCKS_PER_SEC;  // Calculate time in seconds
    printf("\nTime taken to execute algorithm: %lf miliseconds\n", time_taken);

    return 0;
}
