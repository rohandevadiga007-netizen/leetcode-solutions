#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    // Two-pointer swap approach: O(n) time, O(1) space
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

// Local Test Cases
int main() {
    // Test Case 1: Standard case
    char str1[] = {'h', 'e', 'l', 'l', 'o'};
    int size1 = sizeof(str1) / sizeof(str1[0]);
    
    printf("Test 1 - Before: ");
    for (int i = 0; i < size1; i++) printf("%c", str1[i]);
    
    reverseString(str1, size1);
    
    printf(" | After: ");
    for (int i = 0; i < size1; i++) printf("%c", str1[i]);
    printf("\n");

    // Test Case 2: Edge case (Odd length string / single character)
    char str2[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    int size2 = sizeof(str2) / sizeof(str2[0]);

    printf("Test 2 - Before: ");
    for (int i = 0; i < size2; i++) printf("%c", str2[i]);

    reverseString(str2, size2);

    printf(" | After: ");
    for (int i = 0; i < size2; i++) printf("%c", str2[i]);
    printf("\n");

    return 0;
}