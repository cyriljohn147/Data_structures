#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void postfix(char c);
void push(char c);
void operators(char c);
int precedency(char c);
int pop_less_prec(char c);
void is_not_alnum(char c);

char ex[20],stack[20],top=-1;

void main()
{
    int i=0;
    
    printf("\e[1;1H\e[2J");
    printf("Enter your expression:");
    scanf("%s",ex);

    while(ex[i]!='\0')
    {
        postfix(ex[i]);
        i++;
    }

    while(top>-1)
    {
        printf("%c",stack[top]);
        top--;
    }
}

void postfix(char c)
{
    if(isdigit(c))
            printf("%c",c);

    else
        is_not_alnum(c);
}

void is_not_alnum(char c)
{
    if(c=='(')
        push(c);

    else if(c==')')
    {
        while(stack[top]!=')')
        {
            printf("%d",stack[top]);
            top--;
        }
        top--;
    }

    else if(c=='+' || c=='-' || c=='*' || c=='/')
        operators(c);
}

void operators(char c)
{
    //printf("operators=%c\n",c);
    if(top==-1)
    {
        push(c);
    }

    else
    {
        //printf("+=%d\n",precedency(c));
        //printf("%c=%d\n",head->op,precedency(head->op));
        if(precedency(c)>precedency(stack[top]))
        {
            //printf("prec greater=%c\n",head->op);
            push(c);
        }

        else if(precedency(c)<=precedency(stack[top]))
        {
            //printf("prec less than=%c\n",head->op);
            pop_less_prec(c);
        }
    }
}

void push(char c)
{
    top++;
    stack[top]=c;
    //printf(" head=%c ",stack[top]);
}

int precedency(char c)
{
    if(c=='+' || c=='-')
        return 2;

    else if(c=='/' || c=='*')
        return 3;

    else if(c=='(' || c==')')
        return 1;
}

int pop_less_prec(char c)
{

    printf("%c",stack[top]);

    if(top>-1)
        top--;

    else
        return 0;

    if(precedency(c)<=precedency(stack[top]))
        pop_less_prec(c);
}