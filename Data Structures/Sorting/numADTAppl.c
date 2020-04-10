#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

void main()
{
	numADT *N=init();
	int ch,a[10],x;
	
	do
	{
		printf("\nMenu:\n1.Insert\n2.Selection sort\n3.Shell Sort\n4.Display\n5.Exit\nChoice: ");
		scanf("%d",&ch);
		int i;		
		switch(ch)
		{
			case 1:
				printf("Enter size of the array: ");
				scanf("%d",&x);
				for(i=0;i<x;i++)
					scanf("%d",&a[i]);
				insert(N,a,x);
				break;
			case 2:
				selSort(N);
				break;
			case 3:
				shellSort(N);
				break;
			case 4:
				display(N);
			
		}		
	}while(ch!=5);	
	
}


/*
OUTPUT:
-------

PS C:\Users\srina\Desktop> gcc numADTAppl.c -o a
PS C:\Users\srina\Desktop> ./a

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 2

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 1
Enter size of the array: 5
1
4
2
6
9

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 2

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 1 2 4 6 9
Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 1
Enter size of the array: 8
2
6
3
7
5
1
0
6

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 3

Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 4

Array elements are:
 0 1 1 2 2 3 4 5 6 6 6 7 9
Menu:
1.Insert
2.Selection sort
3.Shell Sort
4.Display
5.Exit
Choice: 5
PS C:\Users\srina\Desktop>
*/
