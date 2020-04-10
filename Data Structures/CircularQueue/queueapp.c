#include "cqueue.h"

void main()
{
	queue *Q,*Y;
	Q = (queue*)malloc(sizeof(queue));
	Y = (queue*)malloc(sizeof(queue));
	int cap;
	int ch=6;
	int t;
	char c;
	job j;
	printf("Enter the capacity of the queue: ");
	scanf("%d",&cap);
	initialize(Q,cap);
	initialize(Y,cap);
	while(ch!=5)
	{
		printf("\nQueue operations :\n");
		printf("----- ----------");
		printf("\n1.Add a job \n2.Display waiting time \n3.Display jobs under process \n4.Display no of process in each processor \n5.Exit \nEnter your choice... \n");
		scanf(" %d",&ch);
		switch(ch)
		{	
			case 1:
				printf("\nEnter the data to be inserted...");
				printf("\nJob name: ");
				scanf(" %c",&c);
				printf("\nJob time: ");
				scanf(" %d",&t);
				j.name = c;
				j.time = t;
				if(waitingtime(Q) > waitingtime(Y))
					enqueue(Y,j);
				else if(waitingtime(Q) < waitingtime(Y))
					enqueue(Q,j);
				else 
					enqueue(Q,j);
				break;
			case 2:
				printf("\nWaiting time for processor 1: %d",waitingtime(Q));
				printf("\nWaiting time for processor 2: %d",waitingtime(Y));
				break;
			case 3:
				printf("\nJobs under 1st processor: \n");
				display(Q);
				printf("\nJobs under 2nd processor: \n");
				display(Y);
				break;
			case 4:
				printf("\nSize of 1st processor: %d",Q->size);
				printf("\nSize of 2nd processor: %d",Q->size);
				break;
			case 5:
				exit(0);
		}
	}
}
/* OUTPUT:
   -------
C:\Users\srina\Downloads>gcc queueapp.c -o a

C:\Users\srina\Downloads>a
Enter the capacity of the queue: 2

Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
1

Enter the data to be inserted...
Job name: a

Job time: 4

Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
1

Enter the data to be inserted...
Job name: b

Job time: 3

Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
1

Enter the data to be inserted...
Job name: c

Job time: 6

Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
1

Enter the data to be inserted...
Job name: d

Job time: 7

Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
1

Enter the data to be inserted...
Job name: r

Job time: 3
Queue is full..
Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
2

Waiting time for processor 1: 11
Waiting time for processor 2: 9
Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
3

Jobs under 1st processor:

job name : a
job time : 4
job name : d
job time : 7
Jobs under 2nd processor:

job name : b
job time : 3
job name : c
job time : 6
Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
4

Size of 1st processor: 2
Size of 2nd processor: 2
Queue operations :
----- ----------
1.Add a job
2.Display waiting time
3.Display jobs under process
4.Display no of process in each processor
5.Exit
Enter your choice...
5

C:\Users\srina\Downloads>
*/
				
