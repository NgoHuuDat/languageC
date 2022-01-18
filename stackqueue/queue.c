#include "queue.h"

void InitQueue(Queue* queue)
{
    queue->pHead = NULL;
    queue->pTail = NULL;
}
Nodeq* InitNodeQ(char* data)
{
    Nodeq* node;
    node = (Nodeq*)malloc(sizeof(Nodeq));
    if(node == NULL)
        return NULL;
    node->data = data;
    node->pNext = NULL;
    return node;
}

bool isEmptyQ(Queue* queue)
{
    if(queue->pHead == NULL)
        return true;
    return false;
}

void PushQ(Queue* queue, Nodeq* node)
{
    if(isEmptyQ(queue))
        queue->pHead = queue->pTail = node;
    else
    {
        queue->pTail->pNext = node;
        queue->pTail = node;
    }
}
char* PopQ(Queue* queue)
{
    char* data;
    Nodeq* node;

    if(isEmptyQ(queue))
        data = NULL;
    else
    {
        node = queue->pHead;
        queue->pHead = node->pNext;
        data = node->data;
        free(node);
    }
     return data;
}

char* TopQ(Queue* queue)
{
    char* data;
    if(isEmptyQ(queue))
        data = NULL;
    else
    {
        data = queue->pHead->data;
    }
    return data;
}

void DisplayQ(Queue* queue)
{
    while(!isEmptyQ(queue))
    {
        printf("%s ",PopQ(queue));
    }
    printf("\n");
}

void FreeQueue(Queue* queue)
{
    Nodeq* node = NULL;
    while(queue->pHead != NULL)
    {
        node = queue->pHead;
        queue->pHead = queue->pHead->pNext;
        free(node);
    }
}
