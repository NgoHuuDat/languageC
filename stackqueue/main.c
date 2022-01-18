#include "stack.h"
#include "queue.h"


short Priroty(char* str);
bool CheckOperator(char* str);
char* RemoveSpace(char *str);
char* SubString(const char* source, int x, int n);
void ReadDataFile(FILE* file, Stack* stack, Queue* queue);
void HandleOperator(char* data, Stack* stack, Queue* queue);
int HandlPostfix(Stack* stack, Queue* queue);
int Caculator(int a, int b, char* operator);

int main()
{
    FILE* file;
    Stack stack;
    Queue queue;
    
    InitStack(&stack);
    InitQueue(&queue);
    
    ReadDataFile(file, &stack, &queue);
        
    printf("Result: %d\n",HandlPostfix(&stack,&queue)); 
           
    FreeStack(&stack);
    FreeQueue(&queue);
    return 0;
}

int HandlPostfix(Stack* stack, Queue* queue)
{
    int data;
    char* str;
    int a,b,c;
    
    while(!isEmptyQ(queue))
    {
        str = PopQ(queue);
        if(CheckOperator(str))
        {
            b = atoi(PopS(stack));
            a = atoi(PopS(stack));
            c = Caculator(a,b,str);
            sprintf(str, "%d", c);
            PushS(stack,InitNodeS(str));
        }
        else
        {
            PushS(stack, InitNodeS(str));
        }
    }
    
    data = atoi(PopS(stack));
    return data;
}

void ReadDataFile(FILE* file, Stack* stack, Queue* queue)
{
    char data[50];
    char* buffer;
    char* templ;
    int size;
    
    file = fopen("expression.txt","r");
    fgets(data, sizeof(data), file);
    fclose(file);
    
    RemoveSpace(data);
        
    for(int i = 0; i < strlen(data) - 1; i++)
    {
        if(i == 0)
        {
            buffer = SubString(data,i,1);
            templ = SubString(data,i,1);
        }
        
        buffer = SubString(data,i,1);
        for(int j = 0; j < 8; j++)
        {
            templ = SubString(data,i+j,1);
            if(CheckOperator(templ))
            {
                size = (j == 0?1:j);
                buffer = SubString(data,i,size);
                i +=(j > 0?j -1:j);
                break;
            }
            if(i == strlen(data) - 2)
            {
                buffer = SubString(data,i,1);
                break;
            }
        }
        
        switch(*buffer)
        {
        case '(':
            PushS(stack, InitNodeS(buffer));
            break;
        case ')':
            while(strcmp(TopS(stack),"(") != 0)
            {
                buffer = PopS(stack);
                PushQ(queue, InitNodeQ(buffer));
            }
            buffer = PopS(stack);
            break;
        case '+':
            HandleOperator(buffer,stack,queue);
            break;
        case '-':
            HandleOperator(buffer,stack,queue);
            break;
        case '*':
            HandleOperator(buffer,stack,queue);
            break;
        case '/':
            HandleOperator(buffer,stack,queue);
            break;
        default:
            PushQ(queue, InitNodeQ(buffer));
            break;
        }
    }  
    
    while(!isEmptyS(stack))
    {
        buffer = PopS(stack);
        PushQ(queue, InitNodeQ(buffer));
    }
}

void HandleOperator(char* data, Stack* stack, Queue* queue)
{
    short index;
    if(isEmptyS(stack))
        PushS(stack, InitNodeS(data));
    else
    {
       if(CheckOperator(TopS(stack)))
       {
            if(Priroty(data) > Priroty(TopS(stack)))
            {
                PushS(stack, InitNodeS(data));
            }
            else
            {
                while(1)
                {
                    if(isEmptyS(stack))
                        break;
                    else if(!CheckOperator(TopS(stack)))
                        break;
                    else
                    {
                        if(Priroty(data) <= Priroty(TopS(stack)))
                        {
                            PushQ(queue, InitNodeQ(PopS(stack)));
                        }
                    }      
                }
                PushS(stack, InitNodeS(data));
            }    
       }
       else
        PushS(stack, InitNodeS(data));
    }
}

char* RemoveSpace(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
          str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

char* SubString(const char* source, int x, int n)
{
    char* destination;
    
    destination = (char*)malloc(sizeof(char)*n);
    strncpy(destination, (source + x), n);
    return destination;
}

int Caculator(int a, int b, char* operator)
{
    int data;
    switch(*operator)
    {
    case '+':
        data = a + b;
        break;
    case '-':
        data = a - b;
        break;
    case '*':
        data = a * b;
        break;
    case '/':
        data = a / b;
        break;
    case '%':
        data = a % b;
        break;
    }
}

short Priroty(char* str)
{
    short data;
    switch(*str)
    {
    case '^':
        data = 3;
        break;
    case '*':
        data = 2;
        break;
    case '/':
        data = 2;
        break;
    case '%':
        data = 2;
        break;
    case '+':
        data = 1;
        break;
    case '-':
        data = 1;
        break;
    }
    return data;
}

bool CheckOperator(char* str)
{
    bool data;
    switch(*str)
    {
    case '^':
        data = true;
        break;
    case '*':
        data = true;
        break;
    case '/':
        data = true;
        break;
    case '%':
        data = true;
        break;
    case '+':
        data = true;
        break;
    case '-':
        data = true;
        break;
    case '(':
        data = true;
        break;
    case ')':
        data = true;
        break;
    default:
        data = false;
        break;
    }
    return data;
}
