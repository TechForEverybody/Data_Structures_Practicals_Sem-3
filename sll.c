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
int num;
void get_num()
{
    printf("\n enter the number to be inserted : ");
    scanf("%d", &num);
}
void createLinkList()
{
    get_num();
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
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void insertAtBigin()
{
    struct node *newatbig = NULL;
    newatbig = (struct node *)malloc(sizeof(struct node));
    get_num();
    newatbig->data = num;
    newatbig->next = head;
    head = newatbig;
}
void insertAtEnd()
{
    get_num();
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
void insertAtPosition()
{
    get_num();
    int givenData;
    printf("\nenter the position : ");
    scanf("%d", &givenData);
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
void deleteData()
{
    int givendata;
    printf("\nenter the position : ");
    scanf("%d", &givendata);
    struct node *ptr = NULL, *preptr = NULL;
    ptr = head;
    preptr = ptr;
    if (ptr->data == givendata)
    {
        head = head->next;
        free(ptr);
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
        preptr->next = NULL;
        free(ptr);
        return;
    }

    printf("\n not found");
    return;
}
void main()
{
    int n;
    do
    {
        printf("\n1) for insert at beginning\n2)for insert at end\n3)for insert at the position\n4)for delete the data\n5)print data\n0)for exit\n\t emter the choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insertAtBigin();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            print();
            break;
        }
    } while (n != 0);
}