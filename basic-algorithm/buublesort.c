#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;

    // Shift all non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[i];
            nums[i] = temp;
            lastNonZeroFoundAt++;
        }
    }
}

// Local Test Cases
int main() {
    // Test Case 1: Standard case with mixed zeros
    int nums1[] = {0, 1, 0, 3, 12};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);

    printf("Test 1 - Before: ");
    for (int i = 0; i < size1; i++) printf("%d ", nums1[i]);

    moveZeroes(nums1, size1);

    printf("| After: ");
    for (int i = 0; i < size1; i++) printf("%d ", nums1[i]);
    printf("\n");

    // Test Case 2: Edge case (Single zero element)
    int nums2[] = {0};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    printf("Test 2 - Before: ");
    for (int i = 0; i < size2; i++) printf("%d ", nums2[i]);

    moveZeroes(nums2, size2);

    printf("| After: ");
    for (int i = 0; i < size2; i++) printf("%d ", nums2[i]);
    printf("\n");

    return 0;
}