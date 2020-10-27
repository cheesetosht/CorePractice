#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Represents the node of list.
struct node
{
     int data;
     struct node *next;
};

//Declaring head and tail pointer as null.
struct node *head = NULL;
struct node *tail = NULL;

//This function will add the new node at the end of the list.
void addAtEnd(int data)
{
     //Create new node
     struct node *newNode = (struct node *)malloc(sizeof(struct node));
     newNode->data = data;
     //Checks if the list is empty.
     if (head == NULL)
     {
          //If list is empty, both head and tail would point to new node.
          head = newNode;
          tail = newNode;
          newNode->next = head;
     }
     else
     {
          //tail will point to new node.
          tail->next = newNode;
          //New node will become new tail.
          tail = newNode;
          //Since, it is circular linked list tail will point to head.
          tail->next = head;
     }
}
//Deletes node from the beginning of the list
void deleteStart()
{
     //Checks whether list is empty
     if (head == NULL)
     {
          return;
     }
     else
     {
          //Checks whether contain only one element
          //If not, head will point to next element in the list and tail will point to new head.
          if (head != tail)
          {
               head = head->next;
               tail->next = head;
          }
          //If the list contains only one element
          //then it will remove it and both head and tail will point to null
          else
          {
               head = tail = NULL;
          }
     }
}
//This function will display the nodes of circular linked list
void display()
{
     struct node *current = head;
     if (head == NULL)
     {
          printf("List is empty");
     }
     else
     {
          printf("Adding nodes to the end of the list: \n");
          do
          {
               //Prints each node by incrementing pointer.
               printf("%d ", current->data);
               current = current->next;
          } while (current != head);
          printf("\n");
     }
}

int main()
{
     //Adding 1 to the list
     addAtEnd(1);
     display();
     //Adding 2 to the list
     addAtEnd(2);
     display();
     //Adding 3 to the list
     addAtEnd(3);
     display();
     //Adding 4 to the list
     addAtEnd(4);
     display();
     deleteStart();
     display();
     return 0;
}