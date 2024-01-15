// Matrix Chain Multiplication using dynamic programming

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include <time.h>

int MatrixChainMultiplication(int p[], int n) 
{
  int m[n][n];
  int i, j, k, L, q;
  for (int i = 1; i < n; i++) 
  {
    m[i][i] = 0;
  }
  // Loop through chain lengths (2 to n-1)
  for (int L = 2; L < n; L++) 
  {
    for (int i = 1; i < n - L + 1; i++) 
    {
        j = i + L - 1;
        m[i][j] = INT_MAX;
        for (int k = i; k <= j - 1; k++) 
        {
            q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
            if (q < m[i][j]) 
            {
                m[i][j] = q;
            }
        
        }
    }
    
  }

  // Return final minimum cost of multiplications
  return m[1][n - 1];
}

int main() {
  int n, i;
  double time;
  clock_t start = clock();
  printf("Enter number of matrices\n");
  scanf("%d", &n);
  n++;
  int arr[n];
  printf("Enter dimensions\n");
  start = clock();
  for (i = 0; i < n; i++) {
    printf("Enter  d%d: ", i);
    scanf("%d", &arr[i]);
  }

  // Calculate and display minimum cost
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("Minimum number of multiplications: %d\n", MatrixChainMultiplication(arr, size));

  clock_t end = clock();
  time = ((double)(end - start) + 1000) / CLOCKS_PER_SEC;
  printf("Time taken: %lf milliseconds\n", time);

  return 0;
}
