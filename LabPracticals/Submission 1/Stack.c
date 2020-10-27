#include <stdio.h>
#include <stdlib.h>

int a, b, i, n, top = -1, s[100], c;
void push();
void pop();
void peep();
void change();
void display();

int main()
{
    printf("Enter the number of elements in stack:");
    scanf("%d", &n);

    printf("\n !!stack opreration starts!!");
    while (c != 6)
    {
        printf("\n 1->push \n 2->pop \n 3->peep \n 4->change \n 5->display \n 6->Exit");
        printf("\n Enter Your Choice:");
        scanf("%d", &c);

        switch (c)
        {

        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        }
    }
}

void push()
{

    if (top >= n)
    {
        printf(" \n Stack owerflow!!!");

        exit(1);
    }
    else

    {
        printf(" \n enter the value to be push in stack:");
        scanf("%d", &a);

        top = top + 1;
        s[top] = a;
    }
}

void pop()
{
    if (top < 0)
    {
        printf("stack underflow!!");
        exit(1);
    }

    else
    {
        top = top - 1;
        printf("poped out value is:%d", s[top + 1]);
    }
}

void peep()
{
    if (top < 0)
    {
        printf("stack underflow!!");
        exit(1);
    }
    else
    {
        printf("enter the position of the value from top:");
        scanf("%d", &b);
        printf("value at %d th positon in stack is:%d", b, s[top - b + 1]);
    }
}

void change()
{
    int j;
    if (top < 0)
    {
        printf("stack underflow!!");
        exit(1);
    }
    else
    {
        printf("enter the position of the value to be changed from top:");
        scanf("%d", &b);
        printf("enter the new value:");
        scanf("%d", &j);
        s[top - b + 1] = j;
    }
}
void display()
{
    if (top < 0)
    {
        printf("stack underflow!!");
        exit(1);
    }

    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("\n %d ", s[i]);
        }
    }
}