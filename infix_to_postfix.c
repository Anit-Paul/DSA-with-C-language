#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct stack
{
    char *arr;
    int top;
    int capacity;
}stack;
void init(stack *s,int size)
{
    s->arr=(char*)malloc(size*sizeof(char));
    s->top=-1;
    s->capacity=20;
}
int isfull(stack *s)
{
    return s->top==s->capacity-1;
}
int isempty(stack *s)
{
    return s->top==-1;
}
char peek(stack *s)
{
    return s->arr[s->top];
}
void push(stack *s,char item)
{
    if(!isfull(s))
    {
        s->arr[++s->top]=item;
    }
}
char pop(stack *s)
{
    if(!isempty(s))
    {
        return s->arr[s->top--];
    }
    else 
    return '$';
}
int isoperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int precedence(char c)
{
    if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='^')
    return 3;
    else
    return 0;

}
char* infix_to_postfix(stack *s,char *infix)
{
    int ilen=strlen(infix);
    char *pf=(char*)malloc(ilen+1);
    int i,j,c1=0,c2=0;
    char c;
    for(i=0,j=0;i<ilen;i++)
    {
        if(infix[i]=='\t'||infix[i]==' ')
        {
            continue;
        }
        else if(isalnum(infix[i]))
        {
            pf[j++]=infix[i];
        }
        else if(infix[i]=='(')
        {
            c1++;
            push(s,infix[i]);
        }
        else if(infix[i]==')')
		{
            c2++;
			while(s->top>-1 && peek(s)!='(')
			{
                pf[j++]=pop(s);
			}
			if(s->top==-1 && s->arr[s->top+1]!='(')
			{
				return "invalid";
			}
			else
			s->top=s->top-1;
		}
        else if(isoperator(infix[i]))
        {
            while(precedence(infix[i])<=precedence(peek(s))&&s->top>-1)
            {
                pf[j++]=pop(s);
            }
           
                push(s,infix[i]);
            
        }
    }
    if(c1!=c2)
    {
        return "invalid";
    }
    while(s->top!=-1)
    {
        pf[j++]=pop(s);
    }
    pf[j]='\0';
    return pf;
}
int main()
{
    stack s;
    init(&s,20);
    char infix[20];
    printf("enter your string : ");
    scanf("%s",& infix);
    char *pf=infix_to_postfix(&s,infix);
    printf("%s",pf);
    return 0;
}
