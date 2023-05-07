#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct NODE{
    char data;
    struct NODE* next;

}Node_t,*Node;
Node newNode(char data,Node next)
{
    Node node=(Node)malloc(sizeof(Node_t));
    node->data=data;
    node->next=next;
    return node;
}
void push(Node *pnode,char letter)
{
    *pnode=newNode(letter,*pnode);
}
int pop(Node *pnode)
{
    if((*pnode)==NULL)
    {
        printf("Underflow\n");
        return 0;
    }
    Node temp=*pnode;
    *pnode=temp->next;
    int x=temp->data;
    temp->next=NULL;
    free(temp);
    return x;
}
bool pallindrome(char *str)
{
    int length=strlen(str);
    Node top=NULL;
    for(int i=0;i<length;i++)
    {
        push(&top,str[i]);
    }
    for(int i=0;i<length;i++)
    {
        if(str[i]!=pop(&top))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[500];
    printf("enter A STRING:");
    gets(str);
    printf("\n");
    if(pallindrome(str)==true)
    {
        printf("it is a pallindrome string");
    }
    else{
        printf("it is not a pallindrome string");
    }



}
