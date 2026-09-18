#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;

    // Iterative reversal: O(n) time, O(1) auxiliary space
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }

    return prev; // New head of the reversed list
}

// Helper function to create a node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper function to free allocated memory
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Local Test Cases
int main() {
    // Test Case 1: Standard list [1 -> 2 -> 3 -> 4 -> 5]
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("Test 1 - Before: ");
    printList(head1);

    head1 = reverseList(head1);

    printf("Test 1 - After:  ");
    printList(head1);
    freeList(head1);

    // Test Case 2: Edge case (Single node [1])
    struct ListNode* head2 = createNode(1);

    printf("\nTest 2 - Before: ");
    printList(head2);

    head2 = reverseList(head2);

    printf("Test 2 - After:  ");
    printList(head2);
    freeList(head2);

    return 0;
}