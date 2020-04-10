#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"dijkstrasintf.h"
#include"dijkstrasimpl.h"

void main()
{
	city *C;
	int x,lp=0,op;
	char a[25],b[25];
	C=(city*)malloc(sizeof(city));
	printf("\n No. of vertices : ");
	scanf("%d",&x);
	printf("\n");
	init(C,x);
	getdata(C);
	while(lp==0)
	{
		printf("\n Operations on Graph : ");
		printf("\n [1] Create");
		printf("\n [2] Display");
		printf("\n [3] Dijkstra's Tables");
		printf("\n [4] Dijkstra's Paths");
		printf("\n [5] Exit");
		printf("\n Option : ");
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
				disp(C);
				break;
			}
			case 3:
			{
				printf("\n Source          : ");
				scanf(" %[^\n]",a);				
				dijkstraTable(C,pos(C,a));
				break;
			}
			case 4:
			{
				printf("\n Source          : ");
				scanf(" %[^\n]",a);
				dijkstraPath(C,pos(C,a));
				break;
			}
			case 5:
			{
				lp=1;
				break;
			}
			default:
				printf("\n Invalid option... Re-enter");
		}
	}
	printf("\n");
}

/*

OUTPUT :

surya@DESKTOP-413385J:/mnt/c/Users/pc/Desktop/DSL/Lab Programs/Ass-12$ gcc dijkstrasapp.c -o a
surya@DESKTOP-413385J:/mnt/c/Users/pc/Desktop/DSL/Lab Programs/Ass-12$ ./a

 No. of vertices : 7

 City name : V1
 City name : V2
 City name : V3
 City name : V4
 City name : V5
 City name : V6
 City name : V7

 Operations on Graph :
 [1] Create
 [2] Display
 [3] Dijkstra's Tables
 [4] Dijkstra's Paths
 [5] Exit
 Option : 1

 Check connection :
 Edge count of V1 : 2
 Edges of V1 :
 Edge 1      : V2
 Edge length : 2
 Edge 2      : V4
 Edge length : 1

 Edge count of V2 : 2
 Edges of V2 :
 Edge 1      : V4
 Edge length : 3
 Edge 2      : V5
 Edge length : 10

 Edge count of V3 : 2
 Edges of V3 :
 Edge 1      : V1
 Edge length : 4
 Edge 2      : V6
 Edge length : 5

 Edge count of V4 : 4
 Edges of V4 :
 Edge 1      : V3
 Edge length : 2
 Edge 2      : V5
 Edge length : 2
 Edge 3      : V7
 Edge length : 4
 Edge 4      : V6
 Edge length : 8

 Edge count of V5 : 1
 Edges of V5 :
 Edge 1      : V7
 Edge length : 6

 Edge count of V6 : 0

 Edge count of V7 : 1
 Edges of V7 :
 Edge 1      : V6
 Edge length : 1

 Operations on Graph :
 [1] Create
 [2] Display
 [3] Dijkstra's Tables
 [4] Dijkstra's Paths
 [5] Exit
 Option : 2

 Adjacency Matrix :

 V1              0   1   0   1   0   0   0
 V2              0   0   0   1   1   0   0
 V3              1   0   0   0   0   1   0
 V4              0   0   1   0   1   1   1
 V5              0   0   0   0   0   0   1
 V6              0   0   0   0   0   0   0
 V7              0   0   0   0   0   1   0

 Distance Matrix :

 V1              0   2   0   1   0   0   0
 V2              0   0   0   3   10  0   0
 V3              4   0   0   0   0   5   0
 V4              0   0   2   0   2   8   4
 V5              0   0   0   0   0   0   6
 V6              0   0   0   0   0   0   0
 V7              0   0   0   0   0   1   0

 Operations on Graph :
 [1] Create
 [2] Display
 [3] Dijkstra's Tables
 [4] Dijkstra's Paths
 [5] Exit
 Option : 3

 Source          : V1

 Initial Configuration

 | V    | K     | D     | P     |
 | V1   | 0     | 0     | 0     |
 | V2   | 0     | Inf   | 0     |
 | V3   | 0     | Inf   | 0     |
 | V4   | 0     | Inf   | 0     |
 | V5   | 0     | Inf   | 0     |
 | V6   | 0     | Inf   | 0     |
 | V7   | 0     | Inf   | 0     |


 V1 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 0     | 2     | V1    |
 | V3   | 0     | Inf   | 0     |
 | V4   | 0     | 1     | V1    |
 | V5   | 0     | Inf   | 0     |
 | V6   | 0     | Inf   | 0     |
 | V7   | 0     | Inf   | 0     |


 V4 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 0     | 2     | V1    |
 | V3   | 0     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 0     | 3     | V4    |
 | V6   | 0     | 9     | V4    |
 | V7   | 0     | 5     | V4    |


 V2 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 0     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 0     | 3     | V4    |
 | V6   | 0     | 9     | V4    |
 | V7   | 0     | 5     | V4    |


 V3 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 1     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 0     | 3     | V4    |
 | V6   | 0     | 8     | V3    |
 | V7   | 0     | 5     | V4    |


 V5 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 1     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 1     | 3     | V4    |
 | V6   | 0     | 8     | V3    |
 | V7   | 0     | 5     | V4    |


 V7 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 1     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 1     | 3     | V4    |
 | V6   | 0     | 6     | V7    |
 | V7   | 1     | 5     | V4    |


 V6 is known

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 1     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 1     | 3     | V4    |
 | V6   | 1     | 6     | V7    |
 | V7   | 1     | 5     | V4    |



 Final Configuration

 | V    | K     | D     | P     |
 | V1   | 1     | 0     | 0     |
 | V2   | 1     | 2     | V1    |
 | V3   | 1     | 3     | V4    |
 | V4   | 1     | 1     | V1    |
 | V5   | 1     | 3     | V4    |
 | V6   | 1     | 6     | V7    |
 | V7   | 1     | 5     | V4    |



 Operations on Graph :
 [1] Create
 [2] Display
 [3] Dijkstra's Tables
 [4] Dijkstra's Paths
 [5] Exit
 Option : 4

 Source          : V1

 Paths to V1

 From V1
 Path : V1
 Dist : 0

 From V2
 Path : V2->V1
 Dist : 2

 From V3
 Path : V3->V4->V1
 Dist : 3

 From V4
 Path : V4->V1
 Dist : 1

 From V5
 Path : V5->V4->V1
 Dist : 3

 From V6
 Path : V6->V7->V4->V1
 Dist : 6

 From V7
 Path : V7->V4->V1
 Dist : 5

 Operations on Graph :
 [1] Create
 [2] Display
 [3] Dijkstra's Tables
 [4] Dijkstra's Paths
 [5] Exit
 Option : 5

*/
