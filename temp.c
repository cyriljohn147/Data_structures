#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char *stack;
int top=1;

void main()
{
    stack=(char *)calloc(sizeof(char),10);
    scanf("%s",stack);
    int n1=stack[top]-'0';
    int n2=stack[top-1]-'0';
    printf("%d, %d",n1,n2);
}