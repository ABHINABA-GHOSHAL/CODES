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
Node merge(Node *p,Node *q)
{
    Node l1=*p;
    Node l2=*q;
    if((*q)->data<(*p)->data)
    {
        l1=*q;
        l2=*p;
    }
    Node res=l1;
    while(l1->next!=NULL)
    {
        if(l2->data<l1->next->data)
        {
            Node temp=l1->next;
            l1->next=l2;
            l2->prev=l1;
            
            l1=l2;
            l2=temp;
        }
        else{
            l1=l1->next;
        }
    
    }
    if(l2!=NULL)
    {
        l1->next=l2;
        l2->prev=l1;
    }
    return res;
}
int main()
{
    Node head1=NULL;
    Node head2=NULL;
    int n1,n2;
    printf("enter number of nodes for both:\n");
    scanf("%d%d",&n1,&n2);
    for(int i=0;i<n1;i++)
    {
        int data;
        printf("enter %d element:",i+1);
        scanf("%d",&data);
        add_element(&head1,data);

    }
     for(int i=0;i<n2;i++)
    {
        int data;
        printf("enter %d element:",i+1);
        scanf("%d",&data);
        add_element(&head2,data);

    }
    display(head1);
    display(head2);
    Node res=merge(&head1,&head2);
    display(res);
}