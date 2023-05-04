#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
typedef struct STACK{
    int top;
    unsigned capacity;
    char* array;
} Stack_t,*Stack;
Stack create_stack(unsigned size)
{
    Stack stack=(Stack)malloc(sizeof(Stack_t));
    stack->top=-1;
    stack->capacity=size;
    stack->array=(char*)calloc(stack->capacity,sizeof(char));
    return stack;
}

bool is_full(Stack s)
{
    if(s->top==s->capacity-1)
    {
        return true;
    }
    return false;
}

bool is_empty(Stack s)
{
    if(s->top==-1)
    {
        return true;
    }
    return false;
}
void push(Stack s,char item)
{
    if(is_full(s))
    {
        printf("overflow\n");
        return;
    }
    s->top=s->top+1;
    s->array[s->top]=item;
    printf("%d pushed into stack\n",item);
}
int pop(Stack s)
{
    if(is_empty(s))
    {
        printf("underflow\n");
        return 0;
    }
    int num=s->array[s->top];
    s->top=s->top-1;
    return num;
}
int peek(Stack s)
{
    if(is_empty(s))
    {
        printf("no element in top\n");
        return 0;
    }
    return s->array[s->top];
}
int precedence(char ch)
{
    switch(ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;

                 
           
    }
}
bool isoperator(char ch)
{
    if(ch=='+' || ch=='-'|| ch=='/'|| ch=='*'|| ch=='^')
    {
        return true;
    }
    return false;
}

int main()
{
    char str[500];
    Stack s=create_stack(500);
    printf("enter infix expression using opening bracket and closing brackets:");
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        
    }
}