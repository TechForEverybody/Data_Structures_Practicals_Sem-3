#include <stdio.h>
#include <conio.h>
#define MAX 100
int stack[MAX], ch, top = -1, i, n;
//Push function for inserting an element
void push()
{
    if (top == MAX - 1)
        printf("\n \tstack is overflow\n");
    else
    {
        printf("\n enter the number to be pushed = ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("\n \tpushed number is = %d", stack[top]);
    }
}
//Pop function for deleting  an element
void pop()
{
    if (top == -1)
    {
        printf("\n \tstack is underflow/n");
    }
    else
    {
        n = stack[top];
        printf("\n \tpoped number is = %d\n", stack[top]);
        top--;
    }
}
//display function for display the elements in stack
void display()
{
    if (top == -1)
    {
        printf("\n \tstack is empty\n");
    }
    else
    {
        printf("\n elements in stack are");
        for (i = top; i >=0; i--)
        {
            printf("\n %d", stack[i]);
        }
        printf("\n");
    }
}
//Peek  function for displaying an top  element
void peek()
{
    if (top == -1)
    {
        printf("\n \tstack is empty\n");
    }
    else
    {
        // return stack[top];
        printf("\n \t peek value is %d\n", stack[top]);
    }
}
void main()
{
    while (1)
    {
        printf("\n 1) for push element ");
        printf("\n 2) for pop element");
        printf("\n 3) for  display elements");
        printf("\n 4) for peek value ");
        printf("\n 5) exit ");
        printf("\n enter the choice = ");
        scanf("%d", &ch);
        switch (ch)
        {
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
        case 5:
            goto exit;
        default:
            printf("\n invalid choice");
        }
    }
exit:
    getch();
}