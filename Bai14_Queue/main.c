/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 23/08/2023
*Description: Operations Associated with a Queue
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    uint8_t *array;
    uint8_t size;
    uint8_t front;
    uint8_t rear;
}Queue;

void Init_Queue(Queue *queue, uint8_t size){
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    queue->array = (uint8_t*)malloc(sizeof(uint8_t)*size); 
}

//To check if the queue is empty
bool isEmpty(Queue queue){
    if (queue.front == queue.rear) return true;
    return false;
}

//To check whether the queue is full or not
bool isFull(Queue queue){
    if (queue.rear == queue.size) return true;
    return false;
}

//Removes the element from the frontal side of the queue
void dequeue(Queue *queue){
    if (isEmpty(*queue))
    {
        printf("\nQueue is Empty");
    }else{
        for (int i = queue->front; i < (queue->rear - queue->front); i++)
        {
            queue->array[i]= queue->array[i+1];
        }
         queue->array[(queue->rear)--]='\0';
    }
}

//It inserts elements to the end of the queue
void enqueue(Queue *queue, uint8_t value){
    if (isFull(*queue))
    {
        printf("\nQueue is full");
    }else{
        queue->array[(queue->rear)++]=value;
    }
    
}

//Pointer element responsible for fetching the first element from the queue
uint8_t Front(Queue queue){
    return queue.array[queue.front];
} 

//Pointer element responsible for fetching the last element from the queue
uint8_t Rear(Queue queue){
    return queue.array[queue.rear-1];
}  

//Print elements of queue
void print_Queue(Queue queue){
    for (int i = queue.front; i < queue.rear; i++)
        {
            printf("\n%d",queue.array[i]);
        }
}

int main(int argc, char const *argv[])
{
    Queue queue;

    Init_Queue(&queue,12);

    enqueue(&queue, 2);
    enqueue(&queue, 4);
    //dequeue(&queue);

    //printf("\nElements in Queue: ");
    //print_Queue(queue);
    printf("\nFirst Elements in Queue: %d",Front(queue));
    printf("\nLast Elements in Queue: %d",Rear(queue));
    return 0;
}
