#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void eval(char c);
void push(int num);
void pop(char c);
int arithmetic(int num1,int num2,char c);

int stack[10];
int top=-1;

void main()
{
    int i;
    char *ex=(char*)malloc(sizeof(char)*20);
    printf("\e[1;1H\e[2J");
    printf("==========POSTFIX EVALUATION==========\n");
    printf("Enter a Postfix Expression:");
    scanf("%s",ex);

    while(ex[i]!='\0')
    {
        eval(ex[i]);
        i++;
    }

    free(ex);

    printf("The result of the given postfix expression: %d",stack[0]);
}

void eval(char c)
{
    if(isdigit(c))
    {
        int num=(int)c-'0';
        //printf("\n%d\n",num);
        push(num);
    }   

    else
        pop(c);
}

void push(int num)
{
    top++;
    stack[top]=num;
    //printf("\ntop=%d\n",stack[top]);
}

void pop(char c)
{
    if(top==-1)
        printf("Stack is empty");

    int op=arithmetic(stack[top],stack[top-1],c);
    //printf("\nop=%d\n",op);
    top--;
    stack[top]=op;
    //printf("\ntop=%d\n",stack[top]);
}

int arithmetic(int num1,int num2,char c)
{
    if(c=='+')
        return num1+num2;
    else if(c=='-')
        return num1-num2;
    else if(c=='*')
        return num1*num2;
    else if(c=='/')
        return num1/num2;
}