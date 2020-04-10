#include<stdio.h>
#include<stdlib.h>
#include"search.h"

void main()
{
	numADT *N=init();
	int ch,a[10],x;
	
	do
	{
		printf("\nMenu:\n1.Insert\n2.Linear Search\n3.Binary Search\n4.Display\n5.Exit\nChoice: ");
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
				printf("Element: ");
				scanf("%d",&x);
				i=lSearch(N,x);				
				if(i!=-1)
					printf("\nElement found at position %d",i+1);
				else
					printf("\nElement not found");
				break;
			case 3:
				printf("Element: ");
				scanf("%d",&x);
				i=bSearch(N,x);				
				if(i!=-1)
					printf("\nElement found at position %d",i+1);
				else
					printf("\nElement not found");
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
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 1
Enter size of the array: 5
6
7
5
3
8

Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 2
Element: 6

Element found at position 1
Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 3
Element: 3

Element found at position 1
Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 4

Array elements are:
 3 5 6 7 8
Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 3
Element: 5

Element found at position 2
Menu:
1.Insert
2.Linear Search
3.Binary Search
4.Display
5.Exit
Choice: 5
PS C:\Users\srina\Desktop>

*/
