#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct dict
{
	char word[30];
	char meaning[30];
}dict;

typedef struct node
{
	struct node *left,*right;
	struct dict data;
	int height;
}node;

void display(node *t,int space);
node* search(node *t,char n[]);
static int height (node *t);
node* insert(node*t,dict d);
node* singlerotatewithleft(node *k2);
node* singlerotatewithright(node *k2);
node* doublerotatewithleft(node *k3);
node* doublerotatewithright(node *k3);

