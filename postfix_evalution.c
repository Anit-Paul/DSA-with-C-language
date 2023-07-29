#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
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
    s->capacity=20;
}
void push(stack *s,int item)
{
    if(!isfull(s))
    {
        s->arr[++s->top]=item;
    }
}
int pop(stack *s)
{
    if(!isempty(s))
    {
        return s->arr[s->top--];
    }
}
int isoperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}
int is_operation(stack *s,char *postfix)
{
    int ilen=strlen(postfix);
    int i,n1,n2,n,c;
    for(i=0;i<ilen;i++)
    {
        if(isalnum(postfix[i]))
        {
            c=postfix[i]-'0';
            push(s,c);
        }
        else if(isoperator(postfix[i]))
        {
            switch(postfix[i])
            {
                case '+':
                n1=pop(s);
                n2=pop(s);
                n=n1+n2;
                push(s,n);
                break;
                 case '-':
                n1=pop(s);
                n2=pop(s);
                n=n1-n2;
                push(s,n);
                break;
                 case '*':
                n1=pop(s);
                n2=pop(s);
                n=n1*n2;
                push(s,n);
                break;
                 case '/':
                n1=pop(s);
                n2=pop(s);
                n=n1/n2;
                push(s,n);
                break;
            }
        }
    }
    return pop(s);
}
int main()
{
    stack s;
    init(&s,20);
    char postfix[20]="578+*469/+*";
    int a=is_operation(&s,postfix);
    printf("%d",a);
    return 0;
}
