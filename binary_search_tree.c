#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree = NULL, *temp = NULL;
int element2, choice;

void traversed_pre(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        traversed_pre(ptr->left);
        traversed_pre(ptr->right);
    }
}
void traversed_in(struct node *ptr)
{
    if (ptr != NULL)
    {
        traversed_in(ptr->left);
        printf("%d\t", ptr->data);
        traversed_in(ptr->right);
    }
}
void traversed_post(struct node *ptr)
{
    if (ptr != NULL)
    {
        traversed_post(ptr->left);
        traversed_post(ptr->right);
        printf("%d\t", ptr->data);
    }
}

struct node *insert(struct node *ptr, int element)
{

    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = element;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else
    {
        if (element < ptr->data)
        {
            ptr->left = insert(ptr->left, element);
        }
        else
        {
            ptr->right = insert(ptr->right, element);
        }
    }
    return ptr;
}
struct node *delete (struct node *ptr, int element)
{
    if (ptr == NULL)
    {
        return ptr;
    }
    else
    {
        if (ptr->data > element)
        {
            ptr->left = delete (ptr->left, element);
        }
        else if (ptr->data < element)
        {
            ptr->right = delete (ptr->right, element);
        }
        else
        {
            if (ptr->left == NULL)
            {
                struct node *temp = ptr->right;
                free(ptr);
                return temp;
            }
            if (ptr->right == NULL)
            {
                struct node *temp = ptr->left;
                free(ptr);
                return temp;
            }
            struct node *temp = ptr->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            ptr->data = temp->data;
            ptr->right = delete (ptr->right, ptr->data);
        }
    }
    return ptr;
}
void main()
{
    while (1)
    {
    back:
        printf("\n1)to create tree or insert element");
        printf("\n2)to delete element of tree");
        printf("\n3)to preorder traversed");
        printf("\n4)to inorder traversed");
        printf("\n5)to postorder traversed");
        printf("\n\tenter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nenter the value to be inserted : ");
            scanf("%d", &element2);
            tree = insert(tree, element2);
            printf("indertion completed\n");
            break;
        case 2:
            printf("\nenter the value to be deleted : ");
            scanf("%d", &element2);
            tree = delete (tree, element2);
            break;
        case 3:
            if (tree == NULL)
            {
                printf("\ntree is empty\n");
            }
            else
            {
                printf("\npreorder traversal sequence is as follows\n");
                traversed_pre(tree);
            }
            break;
        case 4:
            if (tree == NULL)
            {
                printf("\ntree is empty\n");
            }
            else
            {
                printf("\ninorder traversal sequence is as follows\n");
                traversed_in(tree);
            }
            break;
        case 5:
            if (tree == NULL)
            {
                printf("\ntree is empty\n");
            }
            else
            {
                printf("\npostorder traversal sequence is as follows\n");
                traversed_post(tree);
            }
            break;
        default:
            printf("\ninvalid choice\n");
            break;
        }
    }
    getch();
}