#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct exp
{
    char op;
    struct exp *next;
};
struct exp *head=NULL;

void postfix(char c);
void push(char c);
void operators(char c);
int precedency(char c);
int pop_less_prec(char c);
void is_not_alnum(char c);

void main()
{
    char s[20];
    int i=0;
    
    printf("\e[1;1H\e[2J");
    printf("Enter your expression:");
    scanf("%s",s);

    while(s[i]!='\0')
    {
        postfix(s[i]);
        i++;
    }

    while(head->next!=NULL)
    {
        printf("%c",head->op);
        head=head->next;
    }

    printf("%c",head->op);
}

void postfix(char c)
{
    if(isalnum(c))
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
        while(head->op!='(')
        {
            printf("%c",head->op);
            head=head->next;
        }
        head=head->next;
    }

    else if(c=='+' || c=='-' || c=='*' || c=='/')
        operators(c);
}

void operators(char c)
{
    //printf("operators=%c\n",c);
    if(head==NULL)
        push(c);

    else
    {
        //printf("+=%d\n",precedency(c));
        //printf("%c=%d\n",head->op,precedency(head->op));
        if(precedency(c)>precedency(head->op))
        {
            //printf("prec greater=%c\n",head->op);
            push(c);
        }

        else if(precedency(c)<=precedency(head->op))
        {
            //printf("prec less than=%c\n",head->op);
            pop_less_prec(c);
        }
    }
}

void push(char c)
{
    struct exp *n=(struct exp *)malloc(sizeof(struct exp));
    n->op=c;
    //printf("push=%c\n",n->op);
    n->next=head;
    head=n;
    //printf("head=%c\n",head->op);
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
    printf("%c",head->op);

    if(head->next!=NULL)
        head=head->next;

    else
        return 0;

    if(precedency(c)<=precedency(head->op))
        pop_less_prec(c);
}
