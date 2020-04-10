#include "expTreeADTIF.h"
#include "expTreeADTImpl.h"

void main()
{
	expADT t;
	initialisen(&t.s);
	printf("\nEnter infix expression to be converted: ");
	scanf("%s",t.infix);
	strcpy(t.postfix,infixtoPostfix(t.infix,&t.s));
	printf("\nPostfix Expression: %s\n",t.postfix);
	createtree(&t);
	printf("\nExpression Tree:\n");
	display(t.p,0);
	t.value=evaluate(t.p);
	printf("\nValue of evaluated expression: %d\n",t.value);
}

/*  OUTPUT:
   --------

C:\Users\srina\Desktop>gcc expTreeADTAppl.c -o a

C:\Users\srina\Desktop>a

Enter infix expression to be converted: 5+7*3+2

Postfix Expression: 573*+2+

Expression Tree:

          2

+

                              3

                    *

                              7

          +

                    5

Value of evaluated expression: 28

C:\Users\srina\Desktop>

*/