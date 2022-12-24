#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define max 5
int queue[max], rear = -1, front = -1, element;

void enqueue()
{
    if ((rear == max - 1 && front == 0))
    {
        printf("\n queue is overflow");
    }
    else if (rear == -1 && front==-1) 
    {
        printf("\n enter the element to be inserted : ");
        scanf("%d", &element);
        front = rear = 0;
        queue[rear] = element;
    }
    else if (rear == max - 1 && front != 0)
    {
        printf("\n enter the element to be inserted : ");
        scanf("%d", &element);
        rear = 0;
        queue[rear] = element;
    }
    else
    {
        printf("\n enter the element to be inserted : ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
    }
}
void dqueue()
{
    if (front == -1)
    {
        printf("\n\t queue ubderflow");
    }
    else
    {
        element = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            if (front == max - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
        printf("\n\t dequeued element is %d", element);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n\t queue is underflow");
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < max; i++)
            {
                printf("%d\t", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d\t", queue[i]);
            }
        }
    }
}

void main()
{
    int n;
    do
    {
        printf("\n1)enqueue\n2)dqueue\n3)display\n0)exit\n\tenter choice : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            display();
            break;
        }
    } while (n != 0);

    getch();
}