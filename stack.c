#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int *arr;
    int top;
    int capacity;
}stack;
int isfull(stack *s)
{
    return s->top==s->capacity-1;
}
int isempty(stack *s)
{
    return s->top==-1;
}
void init(stack *s,int size)
{
    s->arr=(int*)malloc(size*sizeof(int));
    s->top=-1;
    s->capacity=6;
}
void push(stack *s,int data)
{
    if(!isfull(s))
    {
        s->arr[++s->top]=data;
    }
    else
    {
        printf("the stack is full..\n");
    }
}
int pop(stack *s)
{
    if(!isempty(s))
    {
        return s->arr[s->top--];
    }
    else
    {
        printf("no data in the stack..\n");
        return 404;
    }
}

int main()
{
    stack s;
    init(&s,6);
    int c,data,a;
    do
    {
        printf("\n-------------------------------------------------\n");
        printf("1.push\n2.pop\n0.exit\n");
        printf("enter your choice : ");
        scanf("%d",& c);
        switch(c)
        {
            case 1:
            printf("enter your data : ");
            scanf("%d",& data);
            push(&s,data);
            break;
            case 2:
            a=pop(&s);
            printf("the popped element is %d\n",a);
            break;
            
            case 0:
            printf("exit!!");
        }
    } while (c!=0);
    
}