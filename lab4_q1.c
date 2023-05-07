#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
typedef struct STACk
{
    int top;
    int capacity;
    int *arr;


}Stack_t,*Stack;
Stack create_stack(int Size)
{
    Stack s=(Stack)malloc(sizeof(Stack_t));
    s->top=-1;
    s->capacity=Size;
    s->arr=(int*)calloc(Size,sizeof(int));
    return s;
}
bool isempty(Stack s)
{
    if(s->top==-1)
    {
        return true;
    }
    return false;
}
bool isfull(Stack s)
{
    if(s->top==(s->capacity-1))
    {
        return true;
    }
    return false;
}
void push(Stack s,int element)
{
    if(isfull(s))
    {
        printf("overflow\n");
        return;
    }
    s->top=s->top+1;
    s->arr[s->top]=element;
}
int pop(Stack s)
{
    if(isempty(s))
    {
        printf("underflow\n");
        return 0;
    }
    int ele=s->arr[s->top];
    s->top=s->top-1;
    return ele;
}
bool bracket(char *str)
{
    int length=strlen(str);
    Stack s=create_stack(length);
    for(int i=0;i<length;i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            push(s,str[i]);
        }
        else if( str[i]==')' || str[i]=='}' || str[i]==']'){
            if(isempty(s)==false)
            {
                char ch=s->arr[s->top];
                if((ch=='(' && str[i]==')')||(ch=='{' && str[i]=='}')||(ch=='[' && str[i]==']'))
                {
                    pop(s);

                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            }



    }
    if(isempty(s)==true)
    {
        return true;
    }
    else
    {
        return false;
    }


}
int main()
{
    char str[500];
    printf("Enter a string:");
    gets(str);
    printf("\n");
    if(bracket(str))
    {
        printf("IT IS BALANCED\n");

    }
    else
    {
        printf("IT IS NOT BALANCED\n");
    }



}
