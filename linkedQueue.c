#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *rear = NULL, *front = NULL;
void enqueue()
{
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    int element;
    printf("\n enter the element to be inserted = ");
    scanf("%d", &element);
    ptr->data = element;
    if (rear == NULL)
    {
        ptr->next = NULL;
        rear = front = ptr;
    }
    else
    {
        ptr->next = rear;
        rear = ptr;
    }
}
void display()
{
    struct node *ptr;
    if (front == NULL && rear == NULL)
    {
        printf("\n queue under flow");
    }
    else
    {
        ptr = rear;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}
void dqueue()
{
    struct node *ptr, *preptr;
    if (front == NULL)
    {
        printf("\n queue underflow");
    }
    else if (front == rear)
    {
        printf("\n deleted element is = %d", front->data);
        front = rear = NULL;
    }

    else
    {
        ptr = rear;
        preptr = ptr;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        printf("\n deleted element is %d ", ptr->data);
        front = preptr;
        preptr->next = NULL;
        free(ptr);
    }
}

void main()
{
    int n;
    while (1)
    {
        printf("\n1)enqueue\n2)dqueue\n3)display\n0)exit\n\tenter choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            goto exit;
        case 1:
            enqueue();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n invalid choice");
        }
    }
exit:
    getch();
}