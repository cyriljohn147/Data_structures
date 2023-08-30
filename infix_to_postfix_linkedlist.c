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
int precedency(char c);
void pop(char c);
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

            while(head->next!=NULL)
            {
                while(head->op!=')')
                {
                    printf("%c",head->op);
                    head=head->next;
                }
            }
        }

        else if(c=='+' || c=='-' || c=='*' || c=='/')
        {
            if(head==NULL)
            {
                push(c);
                //printf("%c",c);
            }

            else
            {
                if(precedency(c)>precedency(head->op))
                    push(c);

                else if(precedency(c)<=precedency(head->op))
                    pop(c);
            }
        }
}

void push(char c)
{
    struct exp *n=(struct exp *)malloc(sizeof(struct exp));
    n->op=c;
    //printf("%c",n->op);
    n->next=head;
    head=n;
    //printf("%c",head->op);
}

int precedency(char c)
{
    if(c=='+' || c=='-')
        return 1;

    else if(c='/' || c=='*')
        return 2;
}

void pop(char c)
{

    printf("%c",head->op);
    head=head->next;
    
    if(precedency(c)<=precedency(head->op))
        pop(c);
}