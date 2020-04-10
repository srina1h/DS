#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50

typedef struct stack
{
	int s[100];
	int top,n;
}stack;

typedef struct city
{
	int nov;
	char cities[100][100];
	int map[100][100];
	int vis[100];
	stack *S;
}city;

void initializeStack(stack *ot,int x);
int isfull(stack *ot);
int isempty(stack *ot);
void push(stack *ot,int x);
int pop(stack *ot);
int peek(stack *ot);
int size(stack *ot);
void disps(stack *ot);

void initialize(city *c,int x);
void getdata(city *c);
void putdata(city *c);
int pos(city *c,char n[25]);
void create(city *c);
void display(city *c);
int adjustunvisited(city *c,int x);
int notvisited(city *c);
void DFS(city *c,int x);
void DFSend(city *c,int x,int y);
int connect(city *c,int x,int y);