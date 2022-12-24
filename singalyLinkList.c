#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void createLinkList()
{
    int num = 80;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;
    head = ptr;
}
void print()
{
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("\n %d", ptr->data);
        ptr = ptr->next;
    }
}
void insertAtBigin(int num)
{
    struct node *newatbig = NULL;
    newatbig = (struct node *)malloc(sizeof(struct node));
    newatbig->data = num;
    newatbig->next = head;
    head = newatbig;
}
void insertAtEnd(int num)
{
    struct node *ptr = NULL, *p = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    ptr->next = NULL;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
}
void insertAfter()
{
    int num = 70, givenData = 80;
    struct node *ptr = NULL, *p = NULL, *pre;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    p = head;
    pre = p;
    while (pre->data != givenData)
    {
        pre = p;
        p = p->next;
    }
    ptr->next = p;
    pre->next = ptr;
}
void insertBefore()
{
    int num = 100, givenData = 80;
    struct node *ptr = NULL, *p = NULL, *pre;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    p = head;
    while (p->data != givenData)
    {
        pre = p;
        p = p->next;
    }
    ptr->next = p;
    pre->next = ptr;
}
void insertAtPosition()
{
    int num = 50, givenData = 2;
    struct node *ptr = NULL, *p = NULL, *q = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    p = head;
    q = p;
    for (int i = 0; i < givenData - 1; i++)
    {
        q = p;
        p = p->next;
    }
    ptr->next = p;
    q->next = ptr;
}
void delfirstelement()
{
    struct node *ptr = NULL;
    ptr = head;
    head = head->next;
    free(ptr);
}
void deletelastelement()
{
    struct node *ptr = NULL, *preptr = NULL;
    ptr = head;
    preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}
void deleteatposition()
{
    int position = 2;
    struct node *ptr = NULL, *preptr = NULL;
    ptr = head;
    preptr = ptr;
    for (int i = 0; i < position - 1; i++)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}
void deleteData()
{
    int givendata = 70;
    struct node *ptr = NULL, *preptr = NULL;
    ptr = head;
    preptr = ptr;
    if (ptr->data == givendata)
    {
        delfirstelement();
        return;
    }
    while (ptr->next != NULL)
    {

        if (ptr->data == givendata)
        {
            preptr->next = ptr->next;
            free(ptr);
            return;
        }
        else
        {
            preptr = ptr;
        }

        ptr = ptr->next;
    }
    if (ptr->data = givendata)
    {
        deletelastelement();
        return;
    }

    printf("\n not found");
    return;
}



int length(){
    int  count = 0;
    while(head!=NULL)
    {
       head = head -> next;
       count++;
    }
    printf("Lenght:%d",count);
}





void main()
{
    int choice;
    // while (1)
    // {
    //     printf("\n ",);   
    // }
    createLinkList();
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    insertAtEnd(5);
    length();
    getch();
}