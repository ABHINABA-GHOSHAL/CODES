#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;

} Node_t, *Node;
Node newNode(int data)
{
    Node node = (Node)malloc(sizeof(Node_t));
    node->prev = NULL;
    node->next = NULL;
    node->data = data;
    return node;
}
void add_first(Node *pnode, int data)
{
    if (*pnode == NULL)
    {
        *pnode = newNode(data);
        return;
    }
    Node temp=*pnode;
    Node node=newNode(data);
    node->next=temp;
    temp->prev=node;
    *pnode=node;

}
void add_last(Node *pnode, int data)
{
    if (*pnode == NULL)
    {
        add_first(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next != NULL)
    {
        node = node->next;
    }
    Node temp=newNode(data);
    temp->prev=node;
    node->next=temp;
}
void add_at(Node *pnode, int data,int pos)
{
    if (*pnode == NULL)
    {
        add_first(pnode, data);
        return;
    }
    Node node = *pnode;
    int i=1;
    while (i<pos-1)
    {
        node = node->next;
        i++;
    }
    Node temp=newNode(data);
    temp->next=node->next;
    temp->prev=node;
    node->next=temp;
   
}
void remove_first(Node *pnode)
{
    Node node=*pnode;
    *pnode=node->next;
    (*pnode)->prev=NULL;
    node->next=NULL;
    free(node);
}
void remove_last(Node *pnode)
{
    if(*pnode==NULL)
    {
        printf("no node\n");
        return;
    }
    Node node=*pnode;
    while(node->next!=NULL)
    {
        node=node->next;
    }
    Node temp=node->prev;
    temp->next=NULL;
    node->prev=NULL;

}
void remove_at(Node *pnode,int pos)
{
    if(*pnode==NULL)
    {
        printf("no node\n");
        return;
    }
    Node node=*pnode;
    int i=1;
    while(i<pos-1)
    {
        node=node->next;
    }
    Node temp=node->next;
    node->next=temp->next;
    temp->next->prev=node;
    temp->next=NULL;
    temp->prev=NULL;


}
void print(Node pnode)
{
    while (pnode != NULL)
    {
        printf("%d->%d->%d\t", pnode->prev, pnode->data, pnode->next);
        pnode = pnode->next;
    }
    printf("\n");
}
int main()
{
    Node head = NULL;
    add_first(&head, 3);
    add_first(&head, 5);
    add_first(&head, 7);
    print(head);
    add_last(&head, 9);
    add_last(&head, 11);
    print(head);
    add_at(&head,13,3);
    add_at(&head,15,7);
    print(head);
    remove_first(&head);
    print(head);
    remove_last(&head);
    print(head);
    remove_at(&head,2);
    print(head);

}
