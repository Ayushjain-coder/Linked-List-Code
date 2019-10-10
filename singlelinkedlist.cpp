#include<iostream>
#include<stdio.h>
#include<process.h>
void l_insert_beg();
void l_insert_end();
void l_insert_pos();
void l_delete_beg();
void l_delete_end();
void l_delete_pos();
void display();
using namespace std;
typedef struct node
 {
    int info;
    struct node *next;
 }NODE;

NODE *start=NULL,*temp=NULL,*loc=NULL,*cur;
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
        case 1:
            printf("=================================================================\n");
            printf("***********************Linear Linked List************************\n");
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
            case 1: l_insert_beg();
                    break;
            case 2: l_insert_end();
                    break;
            case 3: l_insert_pos();
                    break;
            case 4: l_delete_beg();
                    break;
            case 5: l_delete_end();
                    break;
            case 6: l_delete_pos();
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
void l_insert_beg()
{
    cur=makenode();
    if(start==NULL)
        start=cur;
    else
      cur->next=start;
      start=cur;
}

void l_insert_end()
{
    cur=makenode();
    if(start==NULL)
        start=cur;
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=cur;
    }
}

void l_insert_pos()
{
    int skey;
    cur=makenode();
    printf("Enter the position: ");
    scanf("%d",&skey);
    if(start==NULL)
        start=cur;
    else
    {
        int i=1;
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

void l_delete_beg()
{
    if(start==NULL)
        printf("No node in the linkedlist!!!!\n");
    else
    {
        temp=start;
        start=start->next;
        free(temp);
    }
}

void l_delete_end()
{
    if(start==NULL)
        printf("No node in the linkedlist!!!!\n");
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            loc=temp;
            temp=temp->next;
        }
        loc->next=temp->next;
        free(temp);
        free(loc);
    }
}

void l_delete_pos()
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
        free(temp);
    }
}

void display()
{
     temp=start;
     if(start==NULL)
        printf(".....empty linkedlist!!!\n");
     while(temp!=NULL)
     {
         printf("%d -> ",temp->info);
         temp=temp->next;
     }
     printf("\n");
}
