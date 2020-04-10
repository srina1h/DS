#include"DFSIf.h"
#include"DFSImpl.h"

void main()
{
	city *C;
	int x,lp=0,op;
	char a[25],b[25];
	C=(city*)malloc(sizeof(city));
	printf("\n Enter no of vertices: ");
	scanf("%d",&x);
	printf("\n");
	initialize(C,x);
	getdata(C);
	while(lp==0)
	{
		printf("\n DFS Application: ");
		printf("\n  1)Create");
		printf("\n  2)Display");
		printf("\n  3)Depth first search");
		printf("\n  4)Connectivity check");
		printf("\n  5)Exit");
		printf("\n Enter your choice....");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				create(C);
				break;
			}
			case 2:
			{
				display(C);
				break;
			}
			case 3:
			{
				printf("\n Source: ");
				scanf(" %s",a);
				DFS(C,pos(C,a));
				break;
			}
			case 4:
			{
				printf("\n Source: ");
				scanf(" %s",a);
				printf(" Destination: ");
				scanf(" %s",b);
				if(connect(C,pos(C,a),pos(C,b)))
					printf(" %s - %s connection is there\n",a,b);
				else
					printf(" %s - %s connection is not there\n",a,b);
				break;
			}
			case 5:
			{
				lp=1;
				break;
			}
			default:
				printf("\n Invalid option...");
		}
	}
	printf("\n");
}

/*  OUTPUT:
   --------
   
C:\Users\srina\Desktop>gcc DFSAppl.c -o a

C:\Users\srina\Desktop>a

 Enter no of vertices: 6

 Enter city name: a
 Enter city name: c
 Enter city name: d
 Enter city name: e
 Enter city name: f
 Enter city name: g

 DFS Application:
  1)Create
  2)Display
  3)Depth first search
  4)Connectivity check
  5)Exit
 Enter your choice....1

 Checking connection:
 Edge count of a : 2
 Edges of a :
 Edge 1 : f
 Edge 2 : g

 Edge count of c : 2
 Edges of c :
 Edge 1 : a
 Edge 2 : d

 Edge count of d : 2
 Edges of d :
 Edge 1 : c
 Edge 2 : f

 Edge count of e : 3
 Edges of e :
 Edge 1 : c
 Edge 2 : d
 Edge 3 : g

 Edge count of f : 1
 Edges of f :
 Edge 1 : e

 Edge count of g : 0

 DFS Application:
  1)Create
  2)Display
  3)Depth first search
  4)Connectivity check
  5)Exit
 Enter your choice....2

 Adjacency Matrix:

 a       0  0  0  0  1  1
 c       1  0  1  0  0  0
 d       0  1  0  0  1  0
 e       0  1  1  0  0  1
 f       0  0  0  1  0  0
 g       0  0  0  0  0  0

 DFS Application:
  1)Create
  2)Display
  3)Depth first search
  4)Connectivity check
  5)Exit
 Enter your choice....3

 Source: a
 DFS path: a f e c d g

 DFS Application:
  1)Create
  2)Display
  3)Depth first search
  4)Connectivity check
  5)Exit
 Enter your choice....4

 Source: a
 Destination: e
 Actual path: a f e
 a - e connection is there

 DFS Application:
  1)Create
  2)Display
  3)Depth first search
  4)Connectivity check
  5)Exit
 Enter your choice....5


C:\Users\srina\Desktop>
*/


