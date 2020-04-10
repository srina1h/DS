#include "cityADTIf.h"
#include "cityADTImpl.h"

void main()
{
	int i,n,choice;
	char source[100],dest[100];
	cityADT *C;
	C=(cityADT *)malloc(sizeof(cityADT));
	printf("\nEnter the no of cities: ");
	scanf(" %d",&n);
	create(C,n);
	while(choice!=4)
	{
		printf("\nBFS IMPLEMENTATION: \n 1) Display \n 2) Breadth First Search \n 3) Check Path \n 4) Exit\n Enter your choice");
        scanf(" %d",&choice);
        switch(choice)
        {
        	case 1:
				display(C);
				break;
        	case 2:
            	BFS(C);
            	break;
        	case 3:
	            printf("\nEnter source:");
	            scanf(" %[^\n]",source);
	            printf("\nEnter destination:");
				scanf(" %[^\n]",dest);
	            if(connect(C,source,dest))
					printf("\nPath exists between %s and %s\n",source,dest);
				else
	        		printf("\nPath does not exist between %s to %s\n",source,dest);
	        	break;
	        case 4:
	     		exit(0);
	     	default:
	     		printf("\n Invalid input....");
        }
    }
}  
 
/*  OUTPUT:
   ---------

C:\Users\srina\Desktop>gcc cityADTAppl.c -o a

C:\Users\srina\Desktop>a

Enter the no of cities: 4

Enter the names of cities:

City 1: a

City 2: b

City 3: c

City 4: d

Give connections between cities: 1 if Yes and 0 if No
 Is there link between a and b :1

 Is there link between a and c :1

 Is there link between a and d :0

 Is there link between b and a :0

 Is there link between b and c :0

 Is there link between b and d :1

 Is there link between c and a :0

 Is there link between c and b :0

 Is there link between c and d :1

 Is there link between d and a :0

 Is there link between d and b :0

 Is there link between d and c :0

BFS IMPLEMENTATION:
 1) Display
 2) Breadth First Search
 3) Check Path
 4) Exit
 Enter your choice1
The adjacency matrix is :


0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0
BFS IMPLEMENTATION:
 1) Display
 2) Breadth First Search
 3) Check Path
 4) Exit
 Enter your choice2

 a

 b

 c

 d

BFS IMPLEMENTATION:
 1) Display
 2) Breadth First Search
 3) Check Path
 4) Exit
 Enter your choice3

Enter source:a

Enter destination:b

Path exists between a and b

BFS IMPLEMENTATION:
 1) Display
 2) Breadth First Search
 3) Check Path
 4) Exit
 Enter your choice4

C:\Users\srina\Desktop>

*/ 

