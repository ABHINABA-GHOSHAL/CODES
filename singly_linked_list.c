#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;

}Node_t,*Node;
Node newNode(int data, Node next)
{
    Node node=(Node)malloc(sizeof(Node_t));
    node->data=data;
    node->next=next;
    return node;


}
void addfirst(Node* pnode,int data)
{
    *pnode=newNode(data,*pnode);


}
void addlast(Node *pnode,int data)
{
    if(*pnode==NULL)
    {
        addfirst(pnode,data);
        return;
    }
    Node node=*pnode;
    while(node->next!=NULL)
    {
        node=node->next;
    }
    node->next=newNode(data,node->next);


}
int add_middle(Node *pnode,int data,int pos)
{
    if(*pnode==NULL)
    {
        addfirst(pnode,data);
    }
    Node node=*pnode;
    int i=1;
    while(i<pos-1)
    {
        node=node->next;
        i++;
    }
    node->next=newNode(data,node->next);
    //(node->next)->next=temp;
}
void removefirst(Node *pnode)
{
    if(*pnode==NULL)
    {
        printf("no nodes\n");
        return;
    }
    Node node=*pnode;
    *pnode=node->next;
    node->next=NULL;
    free(node);
}
void removelast(Node *pnode)
{
    if(*pnode==NULL)
    {
        printf("no nodes\n");
        return;
    }
    Node node=*pnode;
    while(node->next->next!=NULL)
    {
        node=node->next;
    }
    Node temp=node->next;
    node->next=NULL;
    free(temp);
}
void remove_at(Node *pnode,int pos)
{
    if(*pnode==NULL)
    {
        printf("no nodes\n");
        return;
    }
    Node node=*pnode;
    int i=1;
    while(i<pos-1)
    {
        node=node->next;
        i++;
    }
    Node temp=node->next;
    node->next=temp->next;
    free(temp);
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
Node reverse(Node *pnode,Node curr,Node prev)
{
    if(curr==NULL)
    {
        *pnode=prev;
        return *pnode;
    }
    Node forward=curr->next;
    reverse(pnode,forward,curr);
    curr->next=prev;
}
int main()
{
    Node head=NULL;
    addfirst(&head,10);
    addfirst(&head,12);
    addfirst(&head,15);
    print(head);
    addlast(&head,11);
    print(head);
    add_middle(&head,5,4);
    print(head);
    /*removefirst(&head);
    print(head);
    removelast(&head);
    print(head);
    remove_at(&head,5);
    print(head);*/
    Node curr=head;
    Node prev=NULL;

    Node head1=reverse(&head,curr,prev);
    print(head1);
}
