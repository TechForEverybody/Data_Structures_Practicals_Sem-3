#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int element, position, start, i;
void display();
void insert_at_big();
void insert_at_end();
void insert_at_position_respect_to_head();
void delete ();


void main()
{
    int ch;
    while (1)
    {
        printf("1)to insert at beginning\n");
        printf("2)to insert at end \n");
        printf("3)to insert at at any position with respect to start position\n");
        printf("4)to delete an element\n");
        printf("5)to print the elements\n");
        printf("6)exit\n");
        printf("\t choose any one of the above : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_at_big();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_position_respect_to_head();
            break;
        case 4:
            delete ();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    }
    getch();
}
void display()
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nlink list is empty\n");
    }
    else
    {
        while (ptr->next != head)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("\n%d\n", ptr->data);
    }
}
void insert_at_big()
{
    struct node *ptr = NULL;
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the element to be inserted = ");
    scanf("%d", &element);
    new_node->data = element;
    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        new_node->next = head;
        ptr->next = new_node;
        head = new_node;
    }
}
void insert_at_end()
{
    struct node *ptr = NULL;
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the element to be inserted = ");
    scanf("%d", &element);
    new_node->data = element;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = head;
}
void insert_at_position_respect_to_head()
{
    struct node *ptr = NULL;
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the element which is to be start element from the position to be count = ");
    scanf("%d", &start);
    printf("enter the position at which the element to be inserted with respect to start to be inserted = ");
    scanf("%d", &position);
    printf("enter the element to be inserted = ");
    scanf("%d", &element);
    new_node->data = element;
    ptr = head;
    while (ptr->data != start)
    {
        ptr = ptr->next;
    }
    for (i = 0; i < position - 1; i++)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}
void delete ()
{
    struct node *ptr = NULL, *preptr = NULL;
    ptr = head;
    preptr = ptr;
    if (ptr == NULL)
    {
        printf("\nlink list is empty can`t perform deletion\n");
    }

    else if (ptr->next == head)
    {
        printf("\n only one element is in the circular link list hence by default it gets deleted\n");
        head = NULL;
        free(ptr);
    }
    else
    {
        printf("enter the element to be deleted = ");
        scanf("%d", &element);
        if (ptr->data == element)
        {
            while (preptr->next != head)
            {
                preptr = preptr->next;
            }
            preptr->next = head->next;
            head = head->next;
            free(ptr);
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == element)
                {
                    preptr->next = ptr->next;
                    free(ptr);
                    return;
                }
                preptr = ptr;
                ptr = ptr->next;
            }
            if (ptr->data == element)
            {
                preptr->next = ptr->next;
                free(ptr);
            }
            else
            {
                printf("element not found\n");
            }
        }
    }
}