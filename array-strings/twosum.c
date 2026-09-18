#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Brute force approach: O(n^2) time, O(1) extra space
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

// Local Test Cases
int main() {
    int returnSize;

    // Test Case 1: Standard case
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int* res1 = twoSum(nums1, 4, target1, &returnSize);
    printf("Test 1 - Expected: [0, 1], Got: ");
    if (res1 != NULL && returnSize == 2) {
        printf("[%d, %d]\n", res1[0], res1[1]);
        free(res1);
    } else {
        printf("No solution found\n");
    }

    // Test Case 2: Edge case (duplicate elements / negative numbers)
    int nums2[] = {-3, 4, 3, 90};
    int target2 = 0;
    int* res2 = twoSum(nums2, 4, target2, &returnSize);
    printf("Test 2 - Expected: [0, 2], Got: ");
    if (res2 != NULL && returnSize == 2) {
        printf("[%d, %d]\n", res2[0], res2[1]);
        free(res2);
    } else {
        printf("No solution found\n");
    }

    return 0;
}