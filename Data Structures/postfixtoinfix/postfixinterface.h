#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
	char a[100];
	int top;
	int limit;
}Stack;

void initialize(Stack *S);
int isFull(Stack *S);
int isEmpty(Stack *S);
void push(Stack *S,char x);
char pop(Stack *S);
void display(Stack *S);
void size(Stack *S);

