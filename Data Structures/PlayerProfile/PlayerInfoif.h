#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player
{
	char name[30];
	char role[10];
	float rr;
}player;

typedef struct node
{
	struct node *left,*right;
	struct player data;
}node;

node* insert(node* t,player p);
node* search(node *t,char n[]);
node* findmin(node *t);
node* findmax(node *t);
node* delete(node *t,char n[]);
void inorder(node *t);
void preorder(node *t);
void postorder(node *t);
void display(node *t, int space);


