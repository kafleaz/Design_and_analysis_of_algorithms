#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

int min(int x, int y, int z) {
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int editDistDP(char str1[], char str2[], int m, int n) {
  int dp[m+1][n+1];
  for (int i=0; i<=m; i++) {
    for (int j=0; j<=n; j++) {
      if (i==0)
        dp[i][j] = j;
      else if (j==0)
        dp[i][j] = i;
      else if (str1[i-1] == str2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                          dp[i-1][j],  // Remove
                          dp[i-1][j-1]); // Replace
    }
  }
  return dp[m][n];
}

int main() {
  char str1[100], str2[100];
  double time;
  clock_t start = clock();
  printf("Enter first string\n");
  scanf("%s", str1);
  printf("Enter second string\n");
  scanf("%s", str2);

  // Calculate and display minimum cost
  int m = strlen(str1);
  int n = strlen(str2);
  printf("Minimum number of edits: %d\n", editDistDP(str1, str2, m, n));

  clock_t end = clock();
  time = ((double)(end - start) + 1000) / CLOCKS_PER_SEC;
  printf("Time taken: %lf milliseconds\n", time);

  return 0;
}