#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
typedef struct STACK{
    int top;
    unsigned capacity;
    int* array;
} Stack_t,*Stack;
Stack create_stack(unsigned size)
{
    Stack stack=(Stack)malloc(sizeof(Stack_t));
    stack->top=-1;
    stack->capacity=size;
    stack->array=(int*)calloc(stack->capacity,sizeof(int));
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
void push(Stack s,int item)
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

int main()
{
    Stack s=create_stack(100);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    printf("%d is popped:\n",pop(s));
    printf("top is:%d\n",peek(s));
    printf("contents of the stack are:\n");
    for(int i=s->top;i>-1;i--)
    {
        printf("%d\n",s->array[i]);
    }
}
