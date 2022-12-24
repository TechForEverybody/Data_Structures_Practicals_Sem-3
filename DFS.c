#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int DFS_Traversal[] = {0, 0, 0, 0, 0, 0, 0},
GRAPH[7][7] = {
{0, 1, 0, 0, 1, 0, 0},
{1, 0, 1, 0, 0, 1, 0},
{0, 1, 0, 1, 0, 1, 1},
{0, 0, 1, 0, 0, 1, 0},
{1, 0, 0, 0, 0, 1, 0},
{0, 1, 2, 1, 1, 0, 0},
{0, 0, 1, 0, 1, 0, 0}
};

void DFS_METHOD(int element){
    printf("%d ",element);
    DFS_Traversal[element]=1;
    for (int i = 0; i < 7; i++)
    {
        if (GRAPH[element][i]==1 && !DFS_Traversal[i]==1)
        {
            DFS_Traversal[i];
            DFS_METHOD(i);
        }
    }
    
}

void main()
{
    DFS_METHOD(0);
}