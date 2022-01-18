#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct nodeq
{
    char* data;
    struct nodeq* pNext;
}Nodeq;

typedef struct queue
{
    Nodeq* pHead;
    Nodeq* pTail;
}Queue;


void InitQueue(Queue* queue);   //Init Queue equal NULL
Nodeq* InitNodeQ(char* data); //Init data and return Node

bool isEmptyQ(Queue* queue);    //Check queue : empty return true and different return false
void PushQ(Queue* queue, Nodeq* node);   //Add data is Node in queue
char* TopQ(Queue* queue);
char* PopQ(Queue* queue);    //Return data in queue and remove Node end

void DisplayQ(Queue* queue);    //Show all data in queue

void FreeQueue(Queue* queue);   //Free memory queue in heap


#endif //QUEUE_H
