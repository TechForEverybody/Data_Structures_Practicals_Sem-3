#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
int i, element, position, choice, choice2, traverse;
void print()
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n  link list is empty\n");
    }
    else
    {
        if (traverse == 1)
        {
            while (ptr != NULL)
            {
                printf("\n%d", ptr->data);
                ptr = ptr->next;
            }
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            while (ptr != NULL)
            {
                printf("\n%d", ptr->data);
                ptr = ptr->prev;
            }
        }
    }
}
void insert_at_bigining()
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nmemory not available\n");
    }
    else
    {
        printf("\nenter element to be added : ");
        scanf("%d", &element);
        new_node->data = element;
        new_node->prev = NULL;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
            printf("\ninsertion success\n");
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            ;
            printf("\ninsertion succes\n");
        }
    }
}
void insert_at_end()
{
    struct node *new_node = NULL, *ptr = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nmemory not available\n");
    }
    else
    {
        printf("\nenter element to be added : ");
        scanf("%d", &element);
        new_node->data = element;
        new_node->next = NULL;
        if (head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
            printf("\ninsertion success\n");
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            new_node->prev = ptr;
            ptr->next = new_node;
            printf("\ninsertion succes\n");
        }
    }
}
void insert_at_given_position()
{
    struct node *new_node = NULL, *ptr = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nmemory not available\n");
    }
    else
    {
        ptr = head;
        printf("\nenter the position at which the element to be inserted : ");
        scanf("%d", &position);
        if (position == 1)
        {
            printf("\nplease achose inesrt at the beginning option\n");
        }
        else
        {
            for (i = 1; i < position - 1; i++)
            {
                if (ptr == NULL)
                {
                    printf("\nelement is less than position entered\n");
                    return;
                }

                ptr = ptr->next;
            }
            if (ptr->next == NULL)
            {
                insert_at_end();
                return;
            }
            printf("\nenter element to be added : ");
            scanf("%d", &element);
            new_node->data = element;

            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
            printf("\ninsertion succes\n");
        }
    }
}
void insert_after_any_element()
{
    struct node *new_node = NULL, *ptr = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nmemory not available\n");
    }
    else
    {
        ptr = head;
        printf("\nenter the element after which element to be inserted : ");
        scanf("%d", &position);
        while (ptr->data != position)
        {
            if (ptr->next == NULL)
            {
                printf("\nelement not in the list\n");
                return;
            }
            ptr = ptr->next;
        }

        if (ptr->next == NULL)
        {
            insert_at_end();
        }
        else
        {
            printf("\nenter element to be added : ");
            scanf("%d", &element);
            new_node->data = element;
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
            printf("\ninsertion succes\n");
        }
    }
}
void insert_before_any_element()
{
    struct node *new_node = NULL, *ptr = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nmemory not available\n");
    }
    else
    {
        ptr = head;
        printf("\nenter the element before which element to be inserted : ");
        scanf("%d", &position);
        if (ptr->data == position)
        {
            insert_at_bigining();
            return;
        }
        while (ptr->next->data != position)
        {
            if (ptr->next->next == NULL)
            {
                printf("\nelement not in the list\n");
                return;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        printf("\nenter element to be added : ");
        scanf("%d", &element);
        new_node->data = element;
        new_node->next = ptr->next;
        new_node->prev = ptr;
        ptr->next->prev = new_node;
        ptr->next = new_node;
        printf("\ninsertion succes\n");
    }
}
void delete_at_beginning()
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nlink list is empty\n");
    }
    else
    {
        if (ptr->next == NULL)
        {
            head = NULL;
            free(ptr);
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            free(ptr);
        }
        printf("\ndeletion is successfull\n");
    }
}
void delete_at_end()
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nlink list is empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->prev == NULL)
        {
            head = NULL;
            free(ptr);
        }
        else
        {
            ptr->prev->next = NULL;
            free(ptr);
        }
        printf("\ndeletion successfull\n");
    }
}
void delete_given_data()
{
    struct node *ptr = NULL;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nlink list is empty\n");
    }
    else
    {
        printf("\nenter data which is to be deleted : ");
        scanf("%d", &element);
        if (ptr->data == element)
        {
            delete_at_beginning();
            return;
        }
        while (ptr->data != element)
        {
            if (ptr->next == NULL)
            {
                printf("\nelement not found\n");
                return;
            }
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            delete_at_end();
            return;
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        printf("\ndeletion successfull\n");
    }
}
void sort()
{
    struct node *ptr = NULL, *preptr = NULL, *temp = NULL;
    int count = 0;
    ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count += 1;
    }
    preptr = head;
    for (i = 0; i < count - 1; i++)
    {
        temp = head;
        for (int j = 0; j < count - 1; j++)
        {
            if (temp->data > temp->next->data)
            {
                element = temp->data;
                temp->data = temp->next->data;
                temp->next->data = element;
                temp = temp->next;
            }
        }
    }
}

void main()
{
    while (1)
    {
    back:
        printf("\n1)for create link list or insert at beginning");
        printf("\n2)for create link list ot insert at end ");
        printf("\n3)insert at given position");
        printf("\n4)insert at after any element ");
        printf("\n5)insert at before any element ");
        printf("\n6)delete at the beginning");
        printf("\n7)delete at the end");
        printf("\n8)delete any specific data");
        printf("\n9)print given link list");
        printf("\n10)exit");
        printf("\n\tenter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_bigining();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_given_position();
            break;
        case 4:
            insert_after_any_element();
            break;
        case 5:
            insert_before_any_element();
            break;
        case 6:
            delete_at_beginning();
            break;
        case 7:
            delete_at_end();
            break;
        case 8:
            delete_given_data();
            break;
        case 9:

            while (1)
            {
                printf("\n\n1)forword printing");
                printf("\n2)reverse printing");
                printf("\n3)sort in ascending");
                printf("\n4)sort in decending order");
                printf("\n5)for go back");
                printf("\n6)for exit");
                printf("\nenter the choice : ");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    traverse = 1;
                    print();
                    break;
                case 2:
                    traverse = 2;
                    print();
                    break;
                case 3:
                    sort();
                    break;
                case 4:
                    sort();
                    break;
                case 5:
                    goto back;
                    break;
                case 6:
                    goto exit;
                    break;
                default:
                    printf("\ninvalid choice\n");
                    break;
                }
            }
            break;
        case 10:
            goto exit;
        default:
            printf("\ninvalid choice\n");
            break;
        }
    }
exit:
    getch();
}