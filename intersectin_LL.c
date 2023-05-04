#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node* next;

}Node_t,*Node;
Node newNode(int data,Node next)
{
    Node node=(Node)malloc(sizeof(Node_t));
    node->data=data;
    node->next=next;
    return node;
}
void add_element(Node *pnode,int data)
{
    if(*pnode==NULL)
    {
        *pnode=newNode(data,*pnode);
        return;
    }
    Node node=*pnode;
    while(node->next!=NULL)
    {
        node=node->next;
    }
    node->next=newNode(data,node->next);

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
void intersection(Node *p,Node *q)
{
    Node tmp1=*p;
    Node tmp2=*q;
    int var=INT_MIN;
    while(tmp1!=NULL)
    {
        while(tmp2!=NULL)
        {
            if(tmp1->data==tmp2->data )
            {
                printf("%d\t",tmp2->data);
                
                
            }
            tmp2=tmp2->next;
        }
        tmp1=tmp1->next;
        tmp2=*q;
    }
}
int main()
{
    Node head1=NULL;
    Node head2=NULL;
    add_element(&head1,1);
    add_element(&head1,2);
    add_element(&head1,3);
    add_element(&head1,4);
    add_element(&head1,2);
    add_element(&head1,3);
    add_element(&head1,7);
    add_element(&head1,7);
    add_element(&head2,1);
    add_element(&head2,3);
    add_element(&head2,2);
    add_element(&head2,4);
    display(head1);
    display(head2);
    intersection(&head1,&head2);


}