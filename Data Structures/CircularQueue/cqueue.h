#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct job
{
	char name;
	int time;
}job;

typedef struct queue 
{
	struct job a[50];
	int front;
	int rear;
	int capacity;
	int size;
}queue;

void initialize(queue *Q,int cap)
{
	Q->front = Q->rear = -1;
	Q->capacity = cap;
	Q->size = 0;
}

int isEmpty(queue *Q)
{
	if(Q->rear == -1)
		return(1);
	else if(Q->size == 0)
		return(1);
	else
		return(0);
}

int isFull(queue *Q)
{
	/*
	if(Q->front == 0 && Q->rear == Q->capacity-1)
		return(1);
	else if(Q->front == Q->rear+1)
		return(1);
	*/
	if(Q->size == Q->capacity)
		return(1);
	else 
		return(0);
}

void enqueue(queue *Q,job j)
{
	if(isFull(Q))
		printf("Queue is full..");
	else
	{
		if(Q->rear == -1)
		{
			Q->rear = Q->front = 0;
			Q->a[Q->rear].name=j.name;
			Q->a[Q->rear].time=j.time;
			Q->size++;
		}
		else if(Q->rear == Q->capacity-1)
		{
			Q->rear = 0;
			Q->a[Q->rear].name=j.name;
			Q->a[Q->rear].time=j.time;
			Q->size++;
		}	
		else
		{
			Q->rear++;
			Q->a[Q->rear].name=j.name;
			Q->a[Q->rear].time=j.time;
			Q->size++;
		}
	}
}

job dequeue(queue *Q)
{
	if(isEmpty(Q))
		printf("Queue is empty...");
	else
	{
		if(Q->front == Q->capacity-1)
		{
			Q->front = 0;
			Q->size--;
			return(Q->a[Q->capacity-1]);
		}
		else 
		{	
			Q->front++;
			Q->size--;
			return(Q->a[Q->front-1]);
		}
	}
}

void display(queue *Q)
{
	if(isEmpty(Q))
		printf("Queue is empty... ");
	else 
	{
		int x;
		if(Q->front < Q->rear )
		{
			for(x=Q->front; x<=Q->rear ; x++)
			{
				printf("\njob name : %c",Q->a[x].name);
				printf("\njob time : %d",Q->a[x].time);
			}
		}
		else
		{
			for(x=Q->front ;x<Q->capacity;x++)
			{
				printf("\njob name : %c",Q->a[x].name);
				printf("\njob time : %d",Q->a[x].time);
			}
			for(x=0;x<=Q->rear;x++)
			{
				printf("\njob name : %c",Q->a[x].name);
				printf("\njob time : %d",Q->a[x].time);
			}
		}
	}
}

int waitingtime(queue *Q)
{
	int time=0,x;
	if(isEmpty(Q))
		time = 0;
	else 
	{
		if(Q->front < Q->rear )
		{
			for(x=Q->front; x<=Q->rear ; x++)
				time+=Q->a[x].time;
		}
		else
		{
			for(x=Q->front ;x<Q->capacity;x++)
				time+=Q->a[x].time;
			for(x=0;x<=Q->rear;x++)
				time+=Q->a[x].time;
		}
	}
	return(time);
}










