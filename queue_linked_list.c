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
        printf("     QUEUE OPERATIONS     ");
        printf("\n--------------------------\n");

        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\nEnter option:");

        scanf("%d",&op);

        switch(op)
        {
            case 1:printf("Enter element to be pushed:");
                scanf("%d",&x);
                enq(x);
                goto s;

            case 2:deq();
                goto s;

            case 3:display();
                goto s;

            case 4:peek();
                goto s;

            case 5:exit(0);

            default:printf("Invalid Input!!!");
        }
}

void enq(int x)
{
    struct node *new= malloc(sizeof(struct node));
    struct node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    new->data=x;
    new->next=NULL;
    temp->next=new;
}

void deq()
{
    if(head==NULL)
        printf("Queue is empty!!!");

    else
        head=head->next;
}

void display()
{
    if(head==NULL)
        printf("Queue is empty");

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