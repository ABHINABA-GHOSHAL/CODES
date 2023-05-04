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
Node rotate(Node *pnode, int k,int n )
{
    if((*pnode)==NULL || (*pnode)->next==NULL)
    {
        return *pnode;
    }
    int i=0;
    Node curr=*pnode;
    while(i<n-k-1)
    {
        curr=curr->next;
        i++;
    }
    Node temp=curr->next;
    curr->next=NULL;
    temp->prev=NULL;
    Node head1=temp;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=*pnode;
    return head1;
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
    printf("original data\n");
    display(head);
    int k;
    printf("enter value of k:");
    scanf("%d",&k);
    Node head2=rotate(&head,k,n);
    printf("Rotated Linked List\n"); 
    display(head2);
}