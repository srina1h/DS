#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "pisif.h"
#include "pisimpl.h"

int generatePIN()
{
	srand(time(0));
	int rno;
	rno = rand() % 1000;
	return rno;
}

void printPerson(pis p)
{
	printf("\nName: ");
	printf("%s", p.name);
	printf("\nAge: ");
	printf("%d", p.age);
	printf("\nSex: ");
	printf("%c", p.sex);
	printf("\nCity Address: ");
	printf("%s", p.cityAdd);
	printf("\nStreet Address: ");
	printf("%s", p.streetAdd);
	printf("\nPIN: %d", p.pin);
}

pis inputData()
{
	struct pis p;
	printf("\nEnter name: ");
	scanf(" %[^\n]", p.name);
	printf("\nEnter Age: ");
	scanf(" %d", &p.age);
	printf("\nEnter Sex: ");
	scanf(" %c", &p.sex);
	printf("\nEnter City Address: ");
	scanf(" %[^\n]", p.cityAdd);
	printf("\nEnter Street Address: ");
	scanf(" %[^\n]", p.streetAdd);
	return p;
}

void main()
{	
	node *head,*tail;
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	initialize(head,tail);
	pis ip;
	int r1;
	mf ratio;
	node *t;
	char name[50];
	int ch=0;
	while(ch!=9)
	{
		printf("\nMENU:\n1. Insert an element after PIN.\n2. Add element at end\n3. Add an element to front\n4. Search by Location\n5. List Senior Citizens.\n6. Sort by Age\n7. Display Ratio male to female\n8. Exit");
		printf("\nEnter your option: ");
		scanf(" %d", &ch);
		switch(ch)
		{
			case 1: ip = inputData();
					ip.pin = generatePIN();
					printf("\nEnter PIN to insert after: ");
					scanf(" %d", &r1);
					insertPIN(head,tail,ip,r1);
					break;
			
			case 2: ip = inputData();
					ip.pin = generatePIN();
					insertEnd(head,tail,ip);
					break;

			case 3: ip = inputData();
					ip.pin = generatePIN();
					insertFront(head,tail,ip);
					break;
			
			case 4: printf("\nEnter Location to search: ");
					scanf(" %[^\n]", name);
					t = locatePerson(head,tail,name);
					displaySenior(t);
					break;

			case 5: printf("\nSenior Citizens: ");
					t = seniorPerson(head,tail);
					displaySenior(t);
					break;

			case 6:	sort(head,tail);
					display(head,tail);
					break;
			case 7:	ratio= returnratio(head,tail);
					printf("\nRatio: %f",ratio.ratio);
					break;
			case 8: 
					exit(0);
			default: printf("\nInvalid Input!");
		}
	}
}
		
/* OUTPUT:
  ---------
C:\Users\srina\Desktop>gcc pisapplv3.c -o a

C:\Users\srina\Desktop>a

MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 2

Enter name: ram

Enter Age: 67

Enter Sex: M

Enter City Address: chennai

Enter Street Address: besant nagar

MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 3

Enter name: rama

Enter Age: 43

Enter Sex: F

Enter City Address: kolkata

Enter Street Address: 23 vihas

MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 5

Senior Citizens:
Name: ram
Age: 67
Sex: M
City Address: chennai
Street Address: besant nagar
PIN: 369
MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 1

Enter name: mohan

Enter Age: 54

Enter Sex: M

Enter City Address: pune

Enter Street Address: 45 avenue

Enter PIN to insert after: 369

MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 6

Printing straight:
Name: rama
Age: 43
Sex: F
City Address: kolkata
Street Address: 23 vihas
PIN: 421
Name: mohan
Age: 54
Sex: M
City Address: pune
Street Address: 45 avenue
PIN: 506
Name: ram
Age: 67
Sex: M
City Address: chennai
Street Address: besant nagar
PIN: 369
Printing in reverse:
Name: ram
Age: 67
Sex: M
City Address: chennai
Street Address: besant nagar
PIN: 369
Name: mohan
Age: 54
Sex: M
City Address: pune
Street Address: 45 avenue
PIN: 506
Name: rama
Age: 43
Sex: F
City Address: kolkata
Street Address: 23 vihas
PIN: 421
MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 7

Ratio: 2.000000
MENU:
1. Insert an element after PIN.
2. Add element at end
3. Add an element to front
4. Search by Location
5. List Senior Citizens.
6. Sort by Age
7. Display Ratio male to female
8. Exit
Enter your option: 8

C:\Users\srina\Desktop>		
		
		
