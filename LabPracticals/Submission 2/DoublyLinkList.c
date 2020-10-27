#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;
void insert_front();
void insert_end();
void delete_end();
void delete_specified();
void display();

int main()
{
    insert_front();
    insert_front();
    insert_end();
    insert_end();
    display();
    delete_specified();
    display();
}

void insert_front()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter value: ");
        scanf("%d",&item);
        if(head == NULL){
            ptr->next = NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head = ptr;
        }
        else{
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next = head;
            head->prev=ptr;
            head = ptr;
        }
    } 
}

void insert_end()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter value: ");
        scanf("%d",&item);
        ptr->data=item;
        if(head == NULL){
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else{
            temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = ptr;
            ptr->prev=temp;
            ptr->next = NULL;
        }
    }
}

void delete_end()
{
    struct node *ptr;
    if(head == NULL){
        printf("Underflow\n");
    }
    else if(head->next == NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        if(ptr->next != NULL){  
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
    }
}

void delete_specified()
{
    struct node *ptr, *temp;
    int val;
    printf("Enter node value(the previous node of this value will be deleted): ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val) ptr = ptr -> next;
    if(ptr == head){
        printf("Can't delete\n");
    }
    // else if(ptr -> next -> next == NULL){
    //     ptr ->next = NULL;
    // }
    else{
        ptr = ptr->prev->prev;
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}