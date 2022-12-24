#include <stdio.h>
#include <conio.h>
// #include <string.h>
#include <stdlib.h>
// #include <math.h>
#define MAX 50
int BFS_Traversal[] = {0, 0, 0, 0, 0, 0, 0},
    GRAPH[7][7] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0}};
int QUEUE[MAX];
int front = -1, rear = -1;

int is_Queue_Empty()
{
    if (front == -1 || front > rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(int element)
{
    // printf("\nQueue is %s", is_Queue_Empty() ? "EMPTY" : "NOT EMPTY");
    // int a = is_Queue_Empty();
    // printf("\nis_Queue_Empty == %d\n", a);

    if (is_Queue_Empty())
    {
        rear = front = 0;
        QUEUE[rear] = element;
    }
    else
    {
        rear = rear + 1;
    }
    QUEUE[rear] = element;
}
int Dequeue()
{
    if (is_Queue_Empty())
    {
        // printf("\nQUEUE UNTERFLOW, CAN'T DEQUEUE\n");
        return -1;
    }
    else if (rear == front)
    {
        int deletedElemet = QUEUE[rear];
        front = rear = -1;
        return deletedElemet;
    }
    else
    {
        int deletedElemet = QUEUE[rear];
        // printf("\tElement deleted from queue is : %d\n", deletedElemet);
        rear--;
        return deletedElemet;
    }
}

void BFS_METHOD(int position)
{
    printf("%d ", position);
    BFS_Traversal[position] = 1;
    Enqueue(position);
    while (!is_Queue_Empty())
    {
        int element = Dequeue();
        for (int i = 0; i < 7; i++)
        {
            if (GRAPH[element][i] == 1 && BFS_Traversal[i] == 0)
            {
                printf("%d ",i);
                BFS_Traversal[i]=1;
                Enqueue(i);
            }
        }
    }
}

// void display()
// {
//     int i;
//     if (is_Queue_Empty())
//         // printf("\n \tQueue is empty \n");
//     else
//     {
//         // printf("Queue is : \n");
//         for (i = front; i <= rear; i++)
//             printf("%d \t", QUEUE[i]);
//         // printf("\n");
//     }
// }

void main()
{
    BFS_METHOD(5);
    // int choice, element;
    // while (1)
    // {
    //     printf("\n1. To Insert element to queue \n");
    //     printf("2. To Delete element from queue \n");
    //     printf("3. To Display the elements of queue \n");
    //     printf("4. To exit \n");
    //     printf("\tEnter your choice : ");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         printf("enter the element in queue : ");
    //         scanf("%d", &element);
    //         Enqueue(element);
    //         break;
    //     case 2:
    //         Dequeue();
    //         break;
    //     case 3:
    //         display();
    //         break;
    //     case 4:
    //         exit(0);
    //     default:
    //         printf("invalid  choice \n");
    //     }
    // }
}