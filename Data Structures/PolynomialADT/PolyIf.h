#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct term
{	int val;
	int exp;

}term;

typedef struct polyADT
{	term t;
	struct polyADT *next;
}polyADT;

void initialize(polyADT *p);
void input(int n,int v[],int e[],polyADT *p);
void print(polyADT *p);
void insertFront(polyADT *p,term x);
void insertEnd(polyADT *p,term x);
void insertAfterTerm(polyADT *p,term x,int e);
void PolyAdd(polyADT *p1, polyADT *p2);
void PolyMul(polyADT *p1, polyADT *p2);
void PolyDeg(polyADT  *p);
int PolyEval(polyADT  *p);
polyADT PolySimplify(polyADT  *p);