#include "stack.h"


void InitStack(Stack* stack)
{
    stack->pTop = NULL;
}

Nodes* InitNodeS(char* data)
{
    Nodes* node;
    node = (Nodes*)malloc(sizeof(Nodes));
    if(node == NULL)
        return NULL;
    node->data = data;
    node->pNext = NULL;
    return node;
}

bool isEmptyS(Stack* stack)
{
    if(stack->pTop == NULL)
        return true;
    return false;
}

char* TopS(Stack* stack)
{
    char* data;
    if(isEmptyS(stack))
        data = NULL;
    else
    {
        data = stack->pTop->data;
    }
    return data;
}

void PushS(Stack* stack, Nodes* node)
{
    if(isEmptyS(stack))
        stack->pTop = node;
    else
    {
        node->pNext = stack->pTop;
        stack->pTop = node;
    }
}
char* PopS(Stack* stack)
{
    char* data;
    Nodes* node;
    
    if(isEmptyS(stack))
        data = NULL;
    else
    {
        data = stack->pTop->data;
        node = stack->pTop;
        stack->pTop = stack->pTop->pNext;
        free(node); 
    }   
     return data;
}

void DisplayS(Stack* stack)
{
    while(!isEmptyS(stack))
    {
        printf(" %s ",PopS(stack));
    }
    printf("\n");
}

void FreeStack(Stack* stack)
{
    Nodes* node;
    while(!isEmptyS(stack))
    {
        node = stack->pTop;
        stack->pTop = stack->pTop->pNext;
        free(node);
    }
}

