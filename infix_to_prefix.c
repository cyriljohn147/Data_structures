#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


char* reverse(const char *c);
void prefix(char c);
void push_stack(char c);
void push_expression(char c);
void is_not_alnum(char c);
void operators(char c);
int precedency(char c);
int pop_less_prec(char c);

int top_stack=-1,top_exp=-1;
char *stack,*expression;

int main()
{
    int i=0;

    stack=(char*)calloc(10,sizeof(char));
    expression=(char *)calloc(21,sizeof(char));
    char *ex=(char*)malloc(sizeof(char)*20);

    printf("\e[1;1H\e[2J");
    printf("Enter your expression:");
    scanf("%s",ex);

    char *rev=reverse(ex);

    
    while(rev[i]!='\0')
    {
        //printf("%c",rev[i]);
        prefix(rev[i]);
        i++;
    }

    i=0;

    while(stack[i]!='\0')
    {
        push_expression(stack[i]);
        i++;
    }

    char *result=reverse(expression);

    printf("%s",result);

    free(stack);
    free(expression);
    free(rev);

    return 0;
}

char *reverse(const char *c)
{
    int length = strlen(c);
    char *rev = (char *)malloc((length + 1) * sizeof(char)); // Include space for null terminator
    for (int i = 0; i < length; i++)
    {
        rev[i] = c[length - 1 - i];
    }
    rev[length] = '\0'; // Null-terminate the reversed string
    return rev;
}

void push_expression(char c)
{
    top_exp++;
    expression[top_exp]=c;
}

void push_stack(char c)
{
    top_stack++;
    stack[top_stack]=c;
}

void prefix(char c)
{
    if(isalnum(c))
        push_expression(c);

    else
        is_not_alnum(c);
}

void is_not_alnum(char c)
{
    if(c==')')
        push_stack(c);

    else if(c=='(')
    {
        while(stack[top_stack]!=')')
        {
            push_expression(stack[top_stack]);
            top_stack--;
        }
        top_stack--;
    }

    else if(c=='+' || c=='-' || c=='*' || c=='/')
        operators(c);
}

void operators(char c)
{
    //printf("operators=%c\n",c);
    if(top_stack==-1)
    {
        push_stack(c);
    }

    else
    {
        //printf("+=%d\n",precedency(c));
        //printf("%c=%d\n",head->op,precedency(head->op));
        if(precedency(c)>precedency(stack[top_stack]))
        {
            //printf("prec greater=%c\n",head->op);
            push_stack(c);
        }

        else if(precedency(c)<=precedency(stack[top_stack]))
        {
            //printf("prec less than=%c\n",head->op);
            pop_less_prec(c);
        }
    }
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
    push_expression(stack[top_stack]);

    if(top_stack>-1)
        top_stack--;

    else
        return 0;

    if(precedency(c)<=precedency(stack[top_stack]))
        pop_less_prec(c);
}