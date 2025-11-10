#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void dKnapsack(int m, int wt[], int p[], int n) {
    int k[n+1][m+1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (wt[i-1] <= j)
                k[i][j] = max(p[i-1] + k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }

    printf("\nMaximum Profit: %d\n", k[n][m]);

    // Traceback to find selected items
    printf("Selected items (1-based index): ");
    int res = k[n][m];
    int w = m;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != k[i-1][w]) {
            // Item i-1 was included
            printf("%d ", i);
            res -= p[i-1];
            w -= wt[i-1];
        }
    }
    printf("\n");
}

int main() {
    int n, m;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], p[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter profits of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    dKnapsack(m, wt, p, n);

    return 0;
}

// Enter number of items: 3
// Enter weights of items:
// 4 5 1
// Enter profits of items:
// 1 2 3
// Enter knapsack capacity: 4

// Maximum Profit: 3
// Selected items (1-based index): 3 