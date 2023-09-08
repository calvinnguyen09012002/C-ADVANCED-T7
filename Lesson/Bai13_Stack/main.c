/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 19/08/2023
*Description: the basic operations served by stacks
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    uint8_t size;
    int capacity;
    uint8_t *array;
}Stacks;

//Init stack
void init_Stacks(Stacks *stack, uint8_t size){
    stack->capacity = -1;
    stack->size = size;
    stack->array = (uint8_t*)malloc(sizeof(uint8_t)*size);
}

//returns true if stack is empty else false
bool isEmpty(Stacks stack) {
    if(stack.capacity == -1) return true;
    return false;
}

//returns true if stack is full else false
bool isFull(Stacks stack) {
    if((stack.capacity+1) == stack.size) return true;
    return false;
}

//to insert an element into the stack
void push(Stacks *stack, uint8_t value) {
    if(isFull(*stack)) printf("Stack is Full \n");
    else stack->array[++(stack->capacity)] = value;
}

//to remove an element from the stack
void pop(Stacks *stack) {
    if(isEmpty(*stack)) {printf("Stack is Empty \n");}
    else {stack->array[(stack->capacity)--] = '\0';}
}

//Returns the top element of the stack.
uint8_t top(Stacks stack) {
    return stack.array[stack.capacity];
}

//returns the size of stack.
uint8_t size(Stacks stack) {
    return (stack.capacity +1);
}

//print elements in Stack.
void print_Stack(Stacks stack){
    if(isEmpty(stack)) printf("Stack is Empty \n");
    else{
        for(int i= 0; i <= stack.capacity; i++)
        {
            printf("\n%d",stack.array[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    Stacks stack;
    /*
    init_Stacks(&stack,12);

    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    pop(&stack);
    
    printf("Size of Stack is %d \n",size(stack));
    
    printf("\nElements in Stack: ");
    print_Stack(stack);
    */

    return 0;
}
