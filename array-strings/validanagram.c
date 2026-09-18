#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    // If lengths differ, they cannot be anagrams
    if (lenS != lenT) {
        return false;
    }

    // Frequency array for 26 lowercase English letters
    int count[26] = {0};

    for (int i = 0; i < lenS; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    // Check if all counts return to zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

// Local Test Cases
int main() {
    // Test Case 1: Standard positive case
    char s1[] = "anagram";
    char t1[] = "nagaram";
    printf("Test 1 (\"anagram\", \"nagaram\") - Expected: 1, Got: %d\n", isAnagram(s1, t1));

    // Test Case 2: Standard negative case
    char s2[] = "rat";
    char t2[] = "car";
    printf("Test 2 (\"rat\", \"car\") - Expected: 0, Got: %d\n", isAnagram(s2, t2));

    // Test Case 3: Edge case (different lengths)
    char s3[] = "a";
    char t3[] = "ab";
    printf("Test 3 (\"a\", \"ab\") - Expected: 0, Got: %d\n", isAnagram(s3, t3));

    return 0;
}