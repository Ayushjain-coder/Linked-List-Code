#include<iostream>
#include<stdio.h>
#include<process.h>
void cd_insert_beg();
void cd_insert_end();
void cd_insert_pos();
void cd_delete_beg();
void cd_delete_end();
void cd_delete_pos();
void display();
using namespace std;
typedef struct node
 {
    int info;
    struct node *prev;
    struct node *next;
 }NODE;

NODE *start=NULL,*temp=NULL,*loc=NULL,*cur,*last=NULL;
int value;

NODE* makenode()
{
    cur=(NODE*)malloc(sizeof(NODE));
    printf("Enter the value: ");
    scanf("%d",&value);
    cur->info=value;
    cur->prev=NULL;
    cur->next=NULL;
    return cur;
}

NODE* lastnode()
{
    temp=start;
    while(temp->next!=start)
        temp=temp->next;
    last=temp;
    return last;
}

int main()
{
    int ch;
    printf("=================================================================\n");
    printf("***************************LINKED LIST***************************\n");
    printf("=================================================================\n");
    printf("1. Linear Linked List\n");
    printf("2. Doubly Linked List\n");
    printf("3. Circular Linked List\n");
    printf("4. Circular Doubly Linked List\n");
    printf("\nChoose Type Linked List: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 4:
            printf("=================================================================\n");
            printf("***********************Circular Doubly Linked List************************\n");
            printf("=================================================================\n");
            printf("1. Insert node at beginning\n");
            printf("2. Insert node at end\n");
            printf("3. Insert node at specify position\n");
            printf("4. Delete node from beginning\n");
            printf("5. Delete node from end\n");
            printf("6. Delete node from specify position\n");
            printf("7. Display\n");
            do
            {
            printf("Enter your choice: ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1: cd_insert_beg();
                    break;
            case 2: cd_insert_end();
                    break;
            case 3: cd_insert_pos();
                    break;
            case 4: cd_delete_beg();
                    break;
            case 5: cd_delete_end();
                    break;
            case 6: cd_delete_pos();
                    break;
            case 7: display();
                    break;
            default: printf("Thanks for using this amazing program!");
                    exit(0);
                    break;
        }
        }while(1);
        default: printf("Thanks for using this amazing program!");
                  exit(0);
    }
}

void cd_insert_beg()
{
    cur=makenode();
    if(start==NULL)
      {
        start=cur;
        cur->next=cur;
        cur->prev=cur;
      }
    else
    {
        last=lastnode();
        cur->next=start;
        start->next->prev=cur;
        start=cur;
        cur->prev=last;
        last->next=cur;
    }
}

void cd_insert_end()
{
    cur=makenode();
    if(start==NULL)
      {
        start=cur;
        cur->next=cur;
        cur->prev=cur;
      }
    else
    {
        last=lastnode();
        last->next=cur;
        cur->prev=last;
        last=cur;
        cur->next=start;
        start->prev=cur;
    }
}

void cd_insert_pos()
{
    int i=1,skey;
    cur=makenode();
    printf("Enter the position: ");
    scanf("%d",&skey);
    if(start==NULL)
    {
        start=cur;
        cur->next=cur;
        cur->prev=cur;
    }
    else
    {
        temp=start;
        while(i<skey)
        {
            loc=temp;
            temp=temp->next;
            i++;
        }
        cur->next=loc->next;
        cur->prev=loc;
        loc->next->prev=cur;
        loc->next=cur;
    }
}

void cd_delete_beg()
{
   if(start==NULL)
    {
     printf("No node in the linkedlist!!!!\n");
    }
   else
   {
     last=lastnode();
     temp=start;
     start=start->next;
     start->prev=last;
     last->next=start;
     free(temp);
   }
}

void cd_delete_end()
{
    if(start==NULL)
    {
     printf("No node in the linkedlist!!!!\n");
    }
    else
    {
        temp=last;
        last=last->prev;
        last->next=start;
        start->prev=last;
        free(temp);
    }
}

void cd_delete_pos()
{
    if(start==NULL)
    {
     printf("No node in the linkedlist!!!!\n");
    }
   else
   {
    int skey;
    printf("Enter the element you want to delete: ");
    scanf("%d",&skey);
    temp=start;
    while(temp->info!=skey)
    {
       loc=temp;
       temp=temp->next;
    }
    loc->next=temp->next;
    temp->next->prev=loc;
    free(temp);
   }
}

void display()
{
     temp=start;
     if(start==NULL)
        printf(".....empty linkedlist!!!\n");
     while(temp->next!=start)
     {
         printf("%d -> ",temp->info);
         temp=temp->next;
     }
     printf("\n");
}

