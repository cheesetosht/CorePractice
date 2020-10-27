#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *rear, *front;

void display()
{
    struct node *temp;

    temp = front;
    if (front == NULL)
    {
        printf("stack under flow!!");
    }
    else
    {
        printf("Queue:\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

void insertnode()
{
    int a;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("stack under flow!!");
    }
    else
    {

        printf("enter the data:");
        scanf("%d", &a);
        temp->data = a;
        if (rear == NULL)
        {
            rear = temp;
            front = temp;
            rear->link = NULL;
            front->link = NULL;
        }
        else
        {
            rear->link = temp;
            temp->link = NULL;
            rear = temp;
        }
    }
    display();
}

void deletenode()
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (front == NULL)
    {
        printf("stack under flow!!");
    }
    else
    {

        temp = front;
        front = front->link;
        free(temp);
    }
    display();
}

int main()
{

    int choice = 10;
    printf("!!here we go again!!");
    printf("!!program starts!!");

    printf("\n  enter 1-> to insert node");
    printf("\n  enter 2-> to deletenode");
    printf("\n  enter 3-> to traverse node");
    printf("\n  enter 0-> to exit");

    while (choice != 0)
    {
        printf("\n enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertnode();
            break;
        case 2:
            deletenode();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("enter proper choice:");
            break;
        }
    }
}