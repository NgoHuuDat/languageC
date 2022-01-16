#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* pRight;
    struct node* pLeft; 
}Node;

//Function with Node
Node* InitNode(int data);   //Function create a node
Node* InsertNode(Node* root, int data); //Function add node in binary tree
Node* SearchNode(Node* root, int data); //Function search data in binary tree
Node* FindMinimum(Node* root);  //Function find data minimum in binary tree

Node* DeleteNode(Node* root, int data); //Function delete node with data input in binary tree

void DisplayLNR(const Node* root);
void DisplayRNL(const Node* root);
void DisplayNRL(const Node* root);
void DisplayNLR(const Node* root);
void DisplayLRN(const Node* root);
void DisplayRLN(const Node* root);

int main()
{
    Node* root;
    root = InitNode(20);
    InsertNode(root,5);
    InsertNode(root,1);
    InsertNode(root,15);
    InsertNode(root,9);
    InsertNode(root,21);
    InsertNode(root,2);
    InsertNode(root,7);
    InsertNode(root,10);
    
    printf("browser left node right:\n");
    DisplayLNR(root);
    printf("\n");
    printf("browser right node left:\n");
    DisplayRNL(root);
    printf("\n");
    printf("browser node right left:\n");
    DisplayNRL(root);
    printf("\n");
    printf("browser node left right:\n");
    DisplayNLR(root);
    printf("\n");
    printf("browser left right node:\n");
    DisplayLRN(root);
    printf("\n");
    printf("browser right left node:\n");
    DisplayRLN(root);
    printf("\n");
    
    
    return 0;
}

Node* InitNode(int data)
{
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    if(node == NULL)
        return NULL;
    node->data = data;
    node->pRight = NULL;
    node->pLeft = NULL;
    return node;
}

Node* InsertNode(Node* root, int data)
{
    if(root == NULL)
        return InitNode(data);
    else if(data > root->data)
        root->pRight = InsertNode(root->pRight,data);
    else
        root->pLeft = InsertNode(root->pLeft, data);
    return root;
}

Node* SearchNode(Node* root, int data)
{
    if(root == NULL || root->data == data)
        return root;
    else if(data > root->data)
        return SearchNode(root->pRight, data);
    else
        return SearchNode(root->pLeft, data);
}

Node* FindMinimum(Node* root)
{
    if(root == NULL)
        return NULL;
    else if(root->pLeft != NULL)
        return FindMinimum(root->pLeft);
    return root;
}


Node* DeleteNode(Node* root, int data)
{
    if(root==NULL)
        return NULL;
    if (data > root->data)
        root->pRight = DeleteNode(root->pRight, data);
    else if(data < root->data)
        root->pLeft = DeleteNode(root->pLeft, data);
    else
    {
        if(root->pLeft == NULL && root->pRight == NULL) //No Children
        {
            free(root);
            return NULL;
        }
        else if(root->pLeft == NULL || root->pRight == NULL)    //One Child
        {
            Node* node;
            if(root->pLeft == NULL)
                node = root->pRight;
            else
                node = root->pLeft;
            free(root);
            return node;
        }
        else     //Two Children
        {
            Node* node = FindMinimum(root->pRight);
            root->data = node->data;
            root->pRight = DeleteNode(root->pRight, node->data);
        }
    }
    return root;
}

void DisplayLNR(const Node* root)
{
    if(root != NULL)
    {
        DisplayLNR(root->pLeft);
        printf(" %d ",root->data);
        DisplayLNR(root->pRight);
    }
}

void DisplayRNL(const Node* root)
{
    if(root != NULL)
    {
        DisplayRNL(root->pRight);
        printf(" %d ",root->data);
        DisplayRNL(root->pLeft);
    }
}
void DisplayNRL(const Node* root)
{
    if(root != NULL)
    {
        printf(" %d ",root->data);
        DisplayNRL(root->pRight);
        DisplayNRL(root->pLeft);
    }
}
void DisplayNLR(const Node* root)
{
    if(root != NULL)
    {
        printf(" %d ",root->data);
        DisplayNLR(root->pLeft);
        DisplayNLR(root->pRight);
    }
}
void DisplayLRN(const Node* root)
{
    if(root != NULL)
    {
        DisplayLRN(root->pLeft);
        DisplayLRN(root->pRight);
        printf(" %d ",root->data);
    }
}
void DisplayRLN(const Node* root)
{
    if(root != NULL)
    {
        DisplayRLN(root->pRight);
        DisplayRLN(root->pLeft);
        printf(" %d ",root->data);
    }
}

