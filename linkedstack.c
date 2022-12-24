#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
int element;
void push()
{
    struct node *ptr = NULL;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\n enter the element to be pushed = ");
    scanf("%d", &element);
    ptr->data = element;
    if (ptr == NULL)
    {
        printf("\n stack is overflow");
    }
    else if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    printf("\n pushed element is %d ", element);
}
void pop()
{
    struct node *ptr = NULL;
    ptr = top;
    if (ptr == NULL)
    {
        printf("\n stack is underflow");
    }
    else
    {
        printf("\t deleted element is %d", ptr->data);
        top = top->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr = NULL;
    ptr = top;
    if (ptr == NULL)
    {
        printf("\n STACK IS EMPTY");
    }

    while (ptr != NULL)
    {
        printf("\n %d", ptr->data);
        ptr = ptr->next;
    }
}
void peek()
{
    if (top == NULL)
    {
        printf("\n stack underflow");
    }
    else
    {
        printf("\n tke peek element in stack is  %d\n", top->data);
    }
}
void main()
{
    int n;
    while (1)
    {
        printf("\n1)push\n2)pop\n3)display\n4)peek\n0)exit\n\tenter choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            goto exit;
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("\n invalid choice");
        }
    }
exit:
getch();
}