#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtStart(int x);
void insertAtEnd(int x);
void insertAfter_nthNode(int n, int x);
void deleteAtStart();
void deleteAtEnd();
void deleteAfter_nthNode(int n);
void display();

int main() 
{
    int op,x,n;

    s:
        printf("\n-------------------------------\n");
        printf("    LINKED LIST OPERATIONS     ");
        printf("\n-------------------------------\n");

        printf("1.Insert at start of the list\n");
        printf("2.Insert at end of list\n");
        printf("3.Insert after nth node in the list\n");
        printf("4.Delete at start of the list\n");
        printf("5.Delete at end of list\n");
        printf("6.Delete after nth node in list\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter option:");

        scanf("%d",&op);

        switch(op)
        {
            case 1:printf("Enter element:");
                scanf("%d",&x);
                insertAtStart(x);
                goto s;

            case 2:printf("Enter element:");
                scanf("%d",&x);
                insertAtEnd(x);
                goto s;

            case 3:printf("Enter position:");
                scanf("%d",&n);
                printf("Enter element:");
                scanf("%d",&x);
                insertAfter_nthNode(n,x);
                goto s;

            case 4:deleteAtStart();
                goto s;

            case 5:deleteAtEnd();
                goto s;

            case 6:printf("Enter position:");
                scanf("%d",&n);
                deleteAfter_nthNode(n);
                goto s;

            case 7:display();
                goto s;

            case 8:exit(0);

            default:printf("Invalid Input!!!!");
                goto s;
        }
}

void insertAtStart(int x)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = head;

    head = new;
}

void insertAtEnd(int x)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;

    struct node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void insertAfter_nthNode(int n, int x)
{
    n--;
    struct node *temp = head->next;
    struct node *prev = head;

    for(int i=0; i<n; i++) {
        temp = temp->next;
        prev = prev->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = temp;
    prev->next = new;
}

void deleteAtStart()
{
    head = head->next;
}

void deleteAtEnd()
{
    if(head == NULL) {
        printf("List empty.\n");
        exit(0);
    }
    struct node *temp = head->next;
    struct node *prev = head;

    while(temp->next != NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;
}

void deleteAfter_nthNode(int n)
{
    n--;
    struct node *temp = head->next;
    struct node *prev = head;

    for(int i=0; i<n; i++) {
        temp = temp->next;
        prev = prev->next;
    }

    prev->next = temp->next;
}

void display()
{
    struct node *temp = head;

    while(temp->next != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}