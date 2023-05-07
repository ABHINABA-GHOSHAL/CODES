#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct QUEUE{
    int front;
    int rear;
    int capacity;
    int *array;

}Queue_t,*Queue;
Queue create_queue(int size)
{
    Queue q=(Queue)malloc(sizeof(Queue_t));
    q->front=0;
    q->rear=0;
    q->capacity=size;
    q->array=(int*)calloc(size,sizeof(int));
    return q;
}
bool isfull(Queue q){
     if((q->capacity-1)==q->rear)
     {
        return true;
     }
     return false;

}
bool isempty(Queue q){
     if(q->front==q->rear)
     {
        return true;
     }
     return false;

}
void enqueue(Queue q,int data)
{
    if(isfull(q))
    {
        printf("overflow");
        return;
    }
    q->array[q->rear]=data;
    q->rear++;
}
int dequeue(Queue q)
{
    if(isempty(q))
    {
        printf("underflow");
        return 0;
    }
    int x=q->array[q->front];
    for(int i=0;i<q->rear-1;i++)
    {
        q->array[i]=q->array[i+1];
    }
    q->rear--;
    return x;

}
int Q_front(Queue q)
{
    if(isempty(q))
    {
        printf("NO element in queue\n");
        return 0;
    }
    return q->array[q->front];
}
void display(Queue q)
{
    if(isempty(q))
    {
        printf("NO element in queue\n");
        return;
    }
    for(int i=q->front;i<q->rear-1;i++)
    {
        printf("%d\t",q->array[i]);
    }
    printf("%d\n");
}
int main()
{
    Queue q=create_queue(100);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    enqueue(q,60);
    display(q);
    dequeue(q);
    display(q);
    printf("%d",Q_front(q));
}


