#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct NODE{
    struct NODE* prev;
    int data;
    struct NODE* next;

}Node_t,*Node;
Node newNode(int data)
{
    Node node=(Node)malloc(sizeof(Node_t));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;

    return node;
}
void add_element(Node *pnode,int data)
{
    if((*pnode)==NULL)
    {
        *pnode=newNode(data);
        return;
    }
    Node temp=*pnode;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node node=newNode(data);
    temp->next=node;
    node->prev=temp;
}
void display(Node pnode)
{
    while(pnode!=NULL)
    {
        printf("%d\t",pnode->data);
        pnode=pnode->next;
    }
    printf("\n");
}
Node kreverse(Node *pnode,int k)
{
    if((*pnode)==NULL || (*pnode)->next==NULL)
    {
        return *pnode;

    }
    Node temp=*pnode;
    Node PREVIOUS=NULL;
    Node curr=temp;
    Node Next=NULL;
    int Count=0;
    while(curr!=NULL && Count<k)
    {
        Next=curr->next;
        curr->next=PREVIOUS;
        curr->prev=Next;
        PREVIOUS=curr;
        curr=Next;
        Count++;


    }
    if(Next!=NULL)
    {
        temp->next=kreverse(&Next,k);
    }
    return PREVIOUS;

}
int main()
{
    Node head=NULL;
    int n;
    printf("enter number of nodes:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("enter %d element:",i+1);
        scanf("%d",&data);
        add_element(&head,data);

    }
    display(head);
    int k;
    printf("enter group of k:\n");
    scanf("%d",&k);
    Node head1=kreverse(&head,k);
    printf("reversed LL is:\n")
    display(head1);

}
