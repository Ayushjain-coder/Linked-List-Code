#include<iostream>
#include<stdio.h>
#include<process.h>
void c_insert_beg();
void c_insert_end();
void c_insert_pos();
void c_delete_beg();
void c_delete_end();
void c_delete_pos();
void display();
using namespace std;
typedef struct node
 {
    int info;
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
        case 3:
            printf("=================================================================\n");
            printf("***********************Circular Linked List************************\n");
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
            case 1: c_insert_beg();
                    break;
            case 2: c_insert_end();
                    break;
            case 3: c_insert_pos();
                    break;
            case 4: c_delete_beg();
                    break;
            case 5: c_delete_end();
                    break;
            case 6: c_delete_pos();
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
                  break;
    }
}
void c_insert_beg()
{
    cur=makenode();
    if(start==NULL)
    {
        start=cur;
        cur->next=start;
    }

    else
    {
      last=lastnode();
      cur->next=start;
      start=cur;
      last->next=start;
    }
}

void c_insert_end()
{
   cur=makenode();
    if(start==NULL)
    {
       start=cur;
       cur->next=start;
    }
    else
    {
        last=lastnode();
        last->next=cur;
        cur->next=start;
    }
}

void c_insert_pos()
{
    int i=1,skey;
    cur=makenode();
    printf("Enter the position: ");
    scanf("%d",&skey);
    if(start==NULL)
        {
         start=cur;
         cur->next=start;
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
        loc->next=cur;
    }
}


void c_delete_beg()
{
    if(start==NULL)
        printf("No node in the linkedlist!!!!\n");
    else
    {
        last=lastnode();
        temp=start;
        start=start->next;
        last->next=start;
        free(temp);
    }
}

void c_delete_end()
{
   if(start==NULL)
        printf("No node in the linkedlist!!!!\n");
   else
   {
     temp=start;
     last=lastnode();
     while(temp->next!=last)
        temp=temp->next;
     temp->next=start;
     free(temp);
   }
}

void c_delete_pos()
{
     if(start==NULL)
        printf("No node in the linkedlist!!!!\n");
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
        temp->next=NULL;
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
     printf("%d -> ",temp->info);
     printf("\n");
}
