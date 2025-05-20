/*
    LeetCode
    Level: Easy
    Title: 83. Remove Duplicates from Sorted List

    Text:
        Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };


 void printLinkList(struct ListNode* startNode)
{
    while(startNode->next != NULL)
    {
        printf("%d ", startNode -> val);
        startNode = startNode->next;
    }
    printf("%d ", startNode -> val);
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* currNode = head;

    while(currNode != NULL){
        if((currNode -> val) == (currNode -> next -> val))
        {
            currNode->next = currNode -> next -> next;
        }
        else
        {
            currNode = currNode -> next;
        }
    }
    return head;
}


int main(){

    return 0;

}