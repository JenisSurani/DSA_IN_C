#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int n)
{
    printf("%d ",n);
    visited[n]=1;
    for (int j = 0; j < 7; j++)
    {
        if(A[n][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
    
}
// Here we don't need to implement stack because function calls already uses stack 

int main()
{

    DFS(4);
    return 0;
}

/*
Authour:Jenish Surani
Purpose: DFS Traversal of graph
Date: 07/09/2024
*/