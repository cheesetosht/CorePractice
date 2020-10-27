#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *link;
};

struct node *head;

void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("empty stack!!");
    }
    else
    {
        while (temp != NULL)
        {
            printf("->%d", temp->data);
            temp = temp->link;
        }
    }
}

void insertfirst()
{
    int a;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("stack over flow!!");
    }

    else
    {
        printf(" enter the number:");
        scanf("%d", &a);
        temp->data = a;
        temp->link = head;
    }

    head = temp;
    display();
}

void insertlast()
{
    struct node *temp, *ptr;
    int a;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("stack overflow");
    }
    else
    {
        printf(" enter the number:");
        scanf("%d", &a);
        temp->data = a;
        ptr = head;
        while (ptr->link != NULL)
        {

            ptr = ptr->link;
        }
        ptr->link = temp;
        temp->link = NULL;
    }
    display();
}

void insertorder()
{

    struct node *temp, *ptr;
    int a;

    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("stack overflow");
    }
    else
    {
        printf(" enter the number:");
        scanf("%d", &a);
        ptr = head;
        while (ptr->data < a)
        {
            ptr = ptr->link;
        }
        temp->data = a;
        temp->link = ptr->link->link;
        ptr->link = temp;
    }
}

void deletefirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("stack is empty!!");
    }
    else
    {
        temp = head;
        head = temp->link;
        free(temp);
    }
    display();
}
void deletebefore()
{
    struct node *temp, *ptr, *ptr1;
    int a;

    if (head == NULL)
    {
        printf("stack is empty!!");
    }

    else if (head->data == a)
    {
        free(head);
        printf("only one node and that too was deleted!!!");
    }

    else
    {

        printf("enter the number befor which node to be deleted:");
        scanf("%d", &a);
        temp = head->link;
        ptr = head;

        while (temp->data != a)
        {

            ptr1 = ptr;
            ptr = ptr->link;
            temp = temp->link;
        }

        if (ptr == head)
        {
            head = temp;
        }
        else
        {
            ptr1->link = temp;
        }

        free(ptr);
    }
    display();
}

void deleteafter()
{
    struct node *temp, *ptr;
    int a;

    if (head == NULL)
    {
        printf("stack is empty!!");
    }

    else if (head->data == a)
    {
        free(head);
        printf("only one node and that too was deleted!!!");
    }

    else
    {

        printf("enter the number after which node to be deleted:");
        scanf("%d", &a);
        temp = head->link;
        ptr = head->link->link;

        while (temp->data != a)
        {
            ptr = ptr->link;
            temp = temp->link;
        }
        if (ptr->link == NULL)
        {
            temp->link = NULL;
        }
        else
        {
            temp->link = ptr->link;
        }

        free(ptr);
        display();
    }
}

int main()
{
    int choice = 10;
    printf("!!!program starts!!!");
    printf("enter 1-> insert node at first \n");
    printf("enter 2-> insert node at last \n");
    printf("enter 3-> insert node in order \n");
    printf("enter 4-> delete node at first \n");
    printf("enter 5-> delete node  before  \n");
    printf("enter 6-> delete node  after \n");

    while (choice != 0)
    {
        printf("\n enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            insertfirst();
            break;
        case 2:
            insertlast();
            break;
        case 3:
            insertorder();
            break;
        case 4:
            deletefirst();
            break;
        case 5:
            deletebefore();
            break;
        case 6:
            deleteafter();
            break;
        case 7:
            display();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("enter proper choice!!!");
        }
    }
}
