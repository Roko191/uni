/*
    LeetCode 
    Level: Easy 
    Title: 206. Reverse Linked List

    Text:
        Given the head of a singly linked list, reverse the list, and return the reversed list.

*/
#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
 struct ListNode* reverseList(struct ListNode* head) {
    /* Declare prev, curr and previous pointer */
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;


    while(curr != NULL){

        // Store next
        next = curr -> next;

        // Reverse current node next pointer
        curr -> next = prev;

        // Move pointers one poisition ahead
        prev = curr;
        curr = next;
    }

    // Prev pointer is now addres of new revrsed linked list
    return prev;

}
