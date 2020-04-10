#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct stack
{
	char c[100];
	int top;
	int limit;
}stack;

struct node
{
	char a;
	struct node *left,*right;
};

typedef struct node node;

typedef struct stackT
{
	node *c[100];
	int top;
	int limit;
}stackT;

typedef struct expADT
{
	char infix[100],postfix[100];
	int value;
	stack s;
	node *p;
	stackT t;	
}expADT;

void initialize(stack *t);
int isempty(stack *t);
int isfull(stack *t);
void Size(stack t);
void disp(stack t);
void push(stack *t,char x);
char pop(stack *t);
char *infixtoPostfix(char *str, stack *s);
int evaluateExp(char *postfix, stack *s);
void initializeT(stackT *t);
int isEmptyT(stackT *t);
int isFullT(stackT *t);
void pushT(stackT *t,node *x);
node* popT(stackT *t);
void createtree(expADT *d);
int evaluate(node *d);
void display(node *p,int space);
