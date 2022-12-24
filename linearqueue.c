#include <stdio.h>
#include <conio.h>
#define MAX 100

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue()
{
  int element;
  if (rear == MAX - 1)
    printf("\n \tQueue Overflow \n");
  else
  {
    if (front == -1)
      front = 0;
    printf("enter the element in queue : ");
    scanf("%d", &element);
    rear = rear + 1;
    queue[rear] = element;
  }
}
void dqueue()
{
  if (front == -1 || front > rear)
  {
    printf("\tQueue Underflow \n");
  }
  else if (front == rear)
  {
    printf("\tElement deleted from queue is : %d\n", queue[front]);
  }
  if (front == rear)
  {
    front = rear = -1;
  }

  else
  {
    printf("\tElement deleted from queue is : %d\n", queue[front]);
    front = front + 1;
  }
}
void display()
{
  int i;
  if (front == -1)
    printf("\n \tQueue is empty \n");
  else
  {
    printf("Queue is : \n");
    for (i = front; i <= rear; i++)
      printf("%d \t", queue[i]);
    printf("\n");
  }
}

void main()
{
  int choice;
  while (1)
  {
    printf("\n1. To Insert element to queue \n");
    printf("2. To Delete element from queue \n");
    printf("3. To Display the elements of queue \n");
    printf("4. To exit \n");
    printf("\tEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
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
    case 4:
      goto exit;
    default:
      printf("invalid  choice \n");
    }
  }
exit:
  getch();
}
