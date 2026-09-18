#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    // Take the first string as the initial prefix reference
    int len = strlen(strs[0]);

    for (int i = 0; i < len; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            // If index is out of bounds for string j or character mismatch occurs
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }

    // If loop completes, the entire first string is the common prefix
    char* result = (char*)malloc((len + 1) * sizeof(char));
    strcpy(result, strs[0]);
    return result;
}

// Local Test Cases
int main() {
    // Test Case 1: Standard case with a common prefix
    char* strs1[] = {"flower", "flow", "flight"};
    char* res1 = longestCommonPrefix(strs1, 3);
    printf("Test 1 - Expected: \"fl\", Got: \"%s\"\n", res1);
    free(res1);

    // Test Case 2: Edge case with no common prefix
    char* strs2[] = {"dog", "racecar", "car"};
    char* res2 = longestCommonPrefix(strs2, 3);
    printf("Test 2 - Expected: \"\", Got: \"%s\"\n", res2);
    free(res2);

    // Test Case 3: Edge case with a single string
    char* strs3[] = {"alone"};
    char* res3 = longestCommonPrefix(strs3, 1);
    printf("Test 3 - Expected: \"alone\", Got: \"%s\"\n", res3);
    free(res3);

    return 0;
}