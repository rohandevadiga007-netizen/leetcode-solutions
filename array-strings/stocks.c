#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // Track the lowest buying price seen so far
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } 
        // Calculate profit if sold today and update max profit
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

// Local Test Cases
int main() {
    // Test Case 1: Standard case (Profit possible)
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Test 1 - Expected: 5, Got: %d\n", maxProfit(prices1, size1));

    // Test Case 2: Edge case (Monotonically decreasing, no profit possible)
    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Test 2 - Expected: 0, Got: %d\n", maxProfit(prices2, size2));

    // Test Case 3: Edge case (Single element)
    int prices3[] = {5};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("Test 3 - Expected: 0, Got: %d\n", maxProfit(prices3, size3));

    return 0;
}