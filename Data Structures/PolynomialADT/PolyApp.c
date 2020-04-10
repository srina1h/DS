#include"PolyIF.h"	
#include"PolyImp.h"

void main()
{
	polyADT *t1 = (polyADT *)malloc(sizeof(polyADT));
	polyADT *t2 = (polyADT *)malloc(sizeof(polyADT));
	polyADT *t3;
	initialize(t1);
	initialize(t2);
	int ch;
	int val[10],exp[10],n,x[10]={0},y[10]={0},i;
	printf("Enter the number of terms of the polynomial:");
	scanf("%d",&n);
	term l;
	int u;
	for(i=0;i<n;i++)
	{
		printf("Enter coeffiecient and power of term %d:",i+1);
		scanf("%d %d",&val[i],&exp[i]);
	}
	input(n,val,exp,t1);
	do
	{
		printf("\nMENU\n1.Insert at Front\n2.Insert at End\n3.Insert after a term\n4.Polynomial Addition\n5.Polynomial multiplication\n6.Deg of the polynomial\n7.Evaluate the polynomial\n8.Polynomial Simplification\n9.Exit\nEnter you choice.... ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("Enter the value and exp of the term:");
					scanf("%d %d",&l.val,&l.exp);
					insertFront(t1,l);
					break;
			case 2:
					printf("Enter the value and exp of the term:");
					scanf("%d %d",&l.val,&l.exp);
					insertEnd(t1,l);
					print(t1);
					break;
			case 3:	printf("Enter the value and exp of the term:");
					scanf("%d %d",&l.val,&l.exp);
					printf("Enter the pow of term after which the term has to be inserted:");
					scanf("%d",&u);
					insertAfterTerm(t1,l,u);
					break;
			case 4:
					printf("Enter the polynomial to be added:\n");
					printf("Enter the no of terms for the polynomial:");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{	
						printf("Enter coeff and power of term: %d:",i+1);
						scanf("%d %d",&val[i],&exp[i]);
					}
					input(n,val,exp,t2);
					PolyAdd(t1,t2);
					break;
			case 5:	printf("Enter the polynomial to be Multiplied: \n");
					printf("Enter the number of terms for the polynomial:");
					scanf("%d",&n);
					for(i=0;i<n;i++)
					{
						printf("Enter coeff and power of term no %d:",i+1);
						scanf("%d %d",&val[i],&exp[i]);
					}
					input(n,val,exp,t2);
					PolyMul(t1,t2);
					break;
			case 6:	PolyDeg(t1);
					break;
			case 7: PolyEval(t1);
					break;
			case 8:	PolySimplify(t1);
					break;
			case 9:
					exit(0);
					break;
			default:
					printf("Invalid input\n");
		}
	}while(1);
}

/*  OUTPUT:
   --------
   
C:\Users\Srinath\Desktop>gcc PolyApp.c -o a

C:\Users\Srinath\Desktop>a
Enter the number of terms of the polynomial:4
Enter coeffiecient and power of term 1:6
3
Enter coeffiecient and power of term 2:5
2
Enter coeffiecient and power of term 3:8
1
Enter coeffiecient and power of term 4:8
0

MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 1
Enter the value and exp of the term:3
5
the polynomail is:3x^5+6x^3+5x^2+8x^1+8x^0
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 2
Enter the value and exp of the term:7
0
the polynomail is:3x^5+6x^3+5x^2+8x^1+8x^0+7x^0
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 3
Enter the value and exp of the term:6
3
Enter the pow of term after which the term has to be inserted3
the polynomail is:3x^5+6x^3+6x^3+5x^2+8x^1+8x^0+7x^0
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 4
Enter the polynomial to be added:
Enter the no of terms for the polynomial:4
Enter coeff and power of term: 1:6
3
Enter coeff and power of term: 2:7
2
Enter coeff and power of term: 3:5
1
Enter coeff and power of term: 4:8
0
the polynomail is:3x^5+12x^3+6x^3+12x^2+13x^1+16x^0+7x^0
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 5
Enter the polynomial to be Multiplied:
Enter the number of terms for the polynomial:3
Enter coeff and power of term no 1:4
2
Enter coeff and power of term no 2:6
1
Enter coeff and power of term no 3:6
0
the polynomail is:33x^7+105x^6+204x^5+18x^8+235x^4+401x^3+323x^2+277x^1+210x^0
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 6

The degree of the polynomia is 5
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 7
Enter value of x: 2

The equations has been evaulated to give the sum = 243
MENU
1.Insert at Front
2.Insert at End
3.Insert after a term
4.Polynomial Addition
5.Polynomial multiplication
6.Deg of the polynomial
7.Evaluate the polynomial
8.Polynomial Simplification
9.Exit
Enter you choice.... 9
C:\Users\Srinath\Desktop>

*/