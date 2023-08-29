#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void main()
{
    int op,x;

    s:
        printf("\n--------------------------\n");
        printf("     STACK OPERATIONS     ");
        printf("\n--------------------------\n");

        printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\nEnter option:");

        scanf("%d",&op);

        switch(op)
        {
            case 1:printf("Enter element to be pushed:");
                scanf("%d",&x);
                push(x);
                goto s;

            case 2:pop();
                goto s;

            case 3:display();
                goto s;

            case 4:peek();
                goto s;

            case 5:exit(0);

            default:printf("Invalid Input!!!");
        }
}

void push(int x)
{
    struct node *new= malloc(sizeof(struct node));

    new->data=x;
    new->next=head;
    head=new;
}

void pop()
{
    if(head==NULL)
        printf("Stack is empty");

    else
    {
        head=head->next;
    }
}

void display()
{
    if(head==NULL)
        printf("Stack is empty");

    else
    {
        struct node *temp=head;

        while(temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }

        printf("%d",temp->data);
    }
}

void peek()
{
    if(head==NULL)
        printf("Stack is empty");

    else
    {
        struct node *temp=head;
        printf("%d",temp->data);
    }
}