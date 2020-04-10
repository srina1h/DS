#include<stdio.h>
#include<stdlib.h>
#include"HashImpl.h"


void main()
{
	Hash *H;
	printf("\nHASH TABLE IMPLEMENTATION\n");
	
	int ch, x;
	
	do{
		printf("\nMenu:\n1.Create a Hash Table\n2.Insert\n3.Search\n4.Display\n5.Exit\nChoice: ");
	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nSize: ");
				scanf("%d",&x);
				H=init(x);
				break;
			case 2:
				printf("\nElement: ");
				scanf("%d",&x);
				insert(H,x);
				break;
			case 3:
				printf("\nEnter element to be searched for: ");
				scanf("%d",&x);
				if(search(H,x))
					printf("Element was found");
				else
					printf("Element was not found");
				break;
			case 4:
				display(H);
		} 
	}while(ch!=5);
}

/*
Output:
HASH TABLE IMPLEMENTATION

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 1

Size: 10

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 12

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 23

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 34

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 34

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 35

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 15

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 2

Element: 75

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 4

Hash Table: 
1 - 
2 - 
3 - 12
4 - 23
5 - 34->34
6 - 75->15->35
7 - 
8 - 
9 - 
10 - 

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 3

Enter element to be searched for: 15
Element was found

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 3

Enter element to be searched for: 67
Element was not found

Menu:
1.Create a Hash Table
2.Insert
3.Search
4.Display
5.Exit
Choice: 5

*/
