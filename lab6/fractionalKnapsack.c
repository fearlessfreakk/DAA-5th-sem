#include <stdio.h>

typedef struct{
    int weight;
    int profit;
    float ratio;
}Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                swap(&items[i], &items[j]);
            }
        }
    }
}

float fractionalKnapsack(Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remain = capacity - currentWeight;
            totalProfit += items[i].profit * ((float)remain / items[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d Profit: ", i + 1);
        scanf("%d", &items[i].profit);
        printf("Item %d Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);
    printf("\nMaximum profit in Knapsack = %.2f\n", maxProfit);

    return 0;
}
