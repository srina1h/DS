#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct City
{    
	char city[100];
	int visit;
}City;

typedef struct cityADT
{                                       
   int n;
   City data[100];
   int adj[50][50];  
}cityADT;

typedef struct Queue
{                                 
   int front,rear;
   char data[100][100];
   int cap,size;
}Queue;

int isFull(Queue *Q);         
int isEmpty(Queue *Q);
void create(cityADT *C, int cities);    
void display(cityADT *C);              
void enqueue(Queue *Q,char x[]);
char* dequeue(Queue *Q);
void BFS(cityADT *C);               
int connect(cityADT *C, char source[], char dest[]);  
