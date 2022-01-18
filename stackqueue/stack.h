#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodes
{
    char* data;
    struct nodes* pNext;
}Nodes;

typedef struct stack
{
    Nodes* pTop;
}Stack;

void InitStack(Stack* stack);
Nodes* InitNodeS(char* data);

bool isEmptyS(Stack* stack);
char* TopS(Stack* stack);
void PushS(Stack* stack, Nodes* node);
char* PopS(Stack* stack);

void DisplayS(Stack* stack);

void FreeStack(Stack* stack);


#endif //STACK_H
