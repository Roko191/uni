#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
        
void createNode(Node **nodeP, int numToStore){
     (*nodeP) = (Node*)malloc(sizeof(Node));
     (*nodeP) -> data = numToStore;
     (*nodeP) -> next = NULL;
}

/*
    This function goes trought list 
    and then check what the last pointer is
    If you know adress of last one addNodeSpecificP()
    would be more optimised
*/
// startNode - list head; numToStore - integer created in new node
/*
    FIX!

    Need to bring pointer to pointer to make changes to
    actual list this way I am doing nothing 

    Or I can just return the pointer itself to list???
*/
void addAndCreateNodeLast(Node** startNode, int numToStore){
    while((*startNode)->next != NULL){
        (*startNode) =  (*startNode) -> next;
    }
    
    Node* toAdd;
    createNode(&toAdd, numToStore);

    (*startNode) = toAdd;
};

void addNodeFirst(){};

void printLinkList(Node* startNode)
{
    while(startNode->next != NULL)
    {
        printf("%d ", startNode -> data);
        startNode = startNode->next;
    }
    printf("%d ", startNode -> data);
}

int main(){
    /* Node init  and memory alloc*/
    Node *head;
    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    Node *third = (Node*)malloc(sizeof(Node));

    /* Assign value to every one */
    first->data = 1;
    second->data = 2;
    third->data = 3;

    // Make every one point to each other
    first->next = second;
    second->next = third;
    third->next = NULL;
    
    // Make head first one duh
    // Copies pointer
    head = first;

    // Iterate trought
    // Start from head and end when we hit null pointer
    printLinkList(head);
    printf("\n");
    
    // // Need to implement function for iteration
    // head = first;

    // Lets add new itme to list
    // Node *fourth;
    // addAndCreateNodeLast(&head, 78);
    
    // Lets add to the start
    Node *newBegining = (Node*)malloc(sizeof(Node));
    newBegining -> data = 0;
    head = newBegining;
    newBegining -> next = first;

    // addNodeLast(head, 63);

    printLinkList(head);
    printf("\n");

    return 0;
}