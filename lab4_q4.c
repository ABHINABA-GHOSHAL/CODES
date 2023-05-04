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
int count(Node *pnode)
{
    Node temp=*pnode;
    int n=0;
    while(temp!=NULL)
    {
        n=n+1;
        temp=temp->next;
    }
    return n;
}
Node sort(Node* pnode,int k)
{

    Node curr=*pnode;
    Node temp=NULL;
    for(int i=0;i<k-1;i++)
    {
        
        temp=curr;
        Node min=curr;
        for(int j=i+1;j<k;j++)
        {
            
            curr=curr->next;
            if(min->data>curr->data)
            {
                min=curr;
            }
        }
        int t1=temp->data;
        temp->data=min->data;
        min->data=t1;
        min=temp->next;
        temp=temp->next;
        curr=temp;
        
    }
    if(temp!=NULL)
    {
        if(count(&(temp->next))<k)
        {
            temp->next=sort(&(temp->next),count(&(temp->next)));

        }
        else{
            temp->next=sort(&(temp->next),k);


        }
    }
    return (*pnode);
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
    Node head2=sort(&head,k);
    printf("sorted k wise is:\n");

    display(head2);
}