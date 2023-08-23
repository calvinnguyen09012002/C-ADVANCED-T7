/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 05/08/2023
*Description: the basic operations served by Linked list.
*/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct Node
{
    uint8_t value;
    struct Node *next;
}Node;

Node *createrNode(uint8_t value)
{
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

//Returns the value of the first element in the list.
uint8_t front(Node *node){
    return node->value;
} 

// Returns the value of the last element in the list.
uint8_t back(Node *node){
    Node *temp = node;
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    return temp->value;
    
}

// Adds a new element ‘g’ at the beginning of the list.
void push_front(Node **ptp, uint8_t value) {
    Node *temp = *ptp;
    *ptp = createrNode(value);
    (*ptp)->next = temp;
}

// Adds a new element ‘g’ at the end of the list.
void push_back(Node **ptp, uint8_t value) {
    if (*ptp == NULL)
    {
        *ptp = createrNode(value);
    }else{
        Node *temp = *ptp;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createrNode(value);
    }
}

// Removes the first element of the list, and reduces the size of the list by 1.
void pop_front(Node **ptp) {
    *ptp = (*ptp)->next;
    return;
}

//Removes the last element of the list, and reduces the size of the list by 1.
void pop_back(Node **ptp) {
    Node *temp = *ptp;
    while(temp->next != NULL)
    {
        if(temp->next->next == NULL){
            free(temp->next);
            temp->next = NULL;
            return;
        }
        temp = temp->next;
    }
    
}


// Inserts new elements in the list before the element at a specified position.
void insert(Node **ptp, uint8_t value, uint8_t position) {
    Node *temp = *ptp;
    uint8_t i=0;

    while (temp ->next != NULL && i != (position - 1))
    {
        temp = temp -> next;
        i++;
    }
    Node *p = createrNode(value);
    p->next = temp->next;
    temp->next = p;
}

// Returns the number of elements in the list.
int size(Node *node) {
    int count = 1;
    for(Node *p = node->next; p !=NULL; p = p->next)
    {
        count++;
    }
    return count;
}


void erase(Node **ptp, uint8_t position){
    uint8_t i = 0;
    Node *temp = *ptp;

    while (temp ->next != NULL)
    {
        i++;
        if(i == position)
        {
            /*Create new pointer to save the node adress to delete*/
            Node *p = temp->next;

            /*Assign the adress of the next node to node to delete*/
            temp->next = temp->next->next;

            /*Free node deleted*/
            free(p);
            return;
        }
        temp = temp->next;
    }
}

void printList(Node *node){
    if(node == NULL) return;
    printf("\n%d",node->value);
    for(Node *p = node->next; p !=NULL; p = p->next)
    {
        printf("\n%d",p->value);
    }
}

int main(int argc, char const *argv[])
{
    Node *node = NULL;

    push_back(&node,2);
    push_back(&node,5);
    push_back(&node,3);

    //printf("\nValue of first Element: %d",front(node));
    //printf("\nValue of last Element: %d",back(node));
    //printf("\nSize of list: %d",size(node));
    //push_front(&node,1);
    //push_back(&node,1);
    //insert(&node, 4, 2);
    //erase(&node,2);
    //pop_back(&node); 
    //pop_front(&node);
    printf("\nLinked list: ");
    printList(node);
    return 0;
}

