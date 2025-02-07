#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createMyarray(struct myarray *a, int usize, int tsize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));  // ahi memory stack ma nahi parntu heap ma allocte karva ma aavi che because function no end thay jay tyare stack ni memeory destroyed thai jay parntu heap ma jya suhdi free() use na karvi tya sudhi memory free na thay.
}

// *(a).total_size; ne aa rite pan lakhi skay a->total_size;

void setVal(struct myarray *b)
{
    int c;
    for (int i = 0; i < b->used_size; i++)
    {
        printf("Enter %d element of the array:\n", i);
        scanf("%d", &c);
        b->ptr[i] = c;
    }
}

void showArr(struct myarray *c)
{
    for (int i = 0; i < c->used_size; i++)
    {
        printf("%dth element of the array is: %d\n", i, c->ptr[i]);
    }
}

int main()
{
    struct myarray marks;
    createMyarray(&marks, 3, 10);
    printf("Array created sucessfully!!\n");
    printf("We are setting the value of array now!\n");
    setVal(&marks);
    printf("We are showing the value of array now!\n");
    showArr(&marks);
    return 0;
}

/*
Authour:Jenish Surani
Purpose: Implementation of the array as an abstract datatype
Date: 20/07/2024
*/

/*
Abstraction on meaning kaik chupavvu  c language ma jyare tame array banavo cho to te kaik aa rite bane che
jeno code tamne show karvama aavto nthi parnatu tamne khali tena features use kari shko.main code ne hide rakhvama aave che
*/