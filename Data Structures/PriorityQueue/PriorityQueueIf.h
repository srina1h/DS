#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct 
{
    int id;
    char name[20];
    float sal;
}emp;

typedef struct 
{
    emp a[100];
    int size;
    int capacity;
}pq;

pq* initialize(int max);
int isFull(pq *p);
int isEmpty(pq *p);
void insert(pq *p,emp x);
void display(pq *p,int in,int lvl);
emp Delete(pq *p);
