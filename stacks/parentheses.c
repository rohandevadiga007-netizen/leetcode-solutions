#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false; // Odd length strings cannot be balanced
    }

    // Allocate stack memory
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // Push opening brackets onto the stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // Process closing brackets
        else {
            if (top == -1) {
                free(stack);
                return false; // Stack empty, no matching open bracket
            }
            
            char lastOpen = stack[top--];
            if ((current == ')' && lastOpen != '(') ||
                (current == '}' && lastOpen != '{') ||
                (current == ']' && lastOpen != '[')) {
                free(stack);
                return false; // Mismatched pair
            }
        }
    }

    bool result = (top == -1); // Valid if stack is completely empty
    free(stack);
    return result;
}

// Local Test Cases
int main() {
    // Test Case 1: Standard valid string
    char s1[] = "()[]{}";
    printf("Test 1 (\"()[]{}\") - Expected: 1, Got: %d\n", isValid(s1));

    // Test Case 2: Standard invalid string (mismatched closing bracket)
    char s2[] = "(]";
    printf("Test 2 (\"(]\") - Expected: 0, Got: %d\n", isValid(s2));

    // Test Case 3: Edge case (unclosed opening bracket / odd length)
    char s3[] = "([)]";
    printf("Test 3 (\"([)]\") - Expected: 0, Got: %d\n", isValid(s3));

    return 0;
}