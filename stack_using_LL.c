#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{
    int data;
    struct NODE* next;

}Node_t,*Node;
Node newNode(int data,Node next)
{
    Node node=(Node)malloc(sizeof(Node_t));
    node->data=data;
    node->next=next;
    return node;
}
void push(Node *pnode,int data)
{
    *pnode=newNode(data,*pnode);
    printf("%d is pushed into stack\n",data);

}
int pop(Node *pnode)
{
    if((*pnode)==NULL)
    {
        printf("undeflow\n");
        return 0;
    }
    Node temp=*pnode;
    (*pnode)=(*pnode)->next;
    int x=temp->data;
    temp->next=NULL;
    return x;

}
int peek(Node *pnode)
{
    if((*pnode)==NULL)
    {
        printf("no element in stack\n");
        return 0;

    }
    return (*pnode)->data;
}
void print(Node pnode)
{
    while(pnode!=NULL)
    {
        printf("%d\t",pnode->data);
        pnode=pnode->next;
    }
    printf("\n");
}
int main()
{
    Node head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    printf("popped element is %d\n",pop(&head));
    printf("top is %d\n",peek(&head));
    printf("elements of the stack are:");
    print(head);

}
