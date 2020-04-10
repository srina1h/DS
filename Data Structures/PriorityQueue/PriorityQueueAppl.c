#include "PriorityQueueIf.h"
#include "PriorityQueueImpl.h"

void main() 
{
    pq *p;
    int max,ch;
    printf("Enter the Heap size:");
    scanf("%d",&max);
    p = initialize(max);
    do
    {
        printf("Priority Queue:\n1) Insert\n2) Delete\n3) Display\n4) Exit\nEnter Your Choice....");
        scanf("%d",&ch);        
        switch(ch)
        {
            case 1:
            {
                emp mx=input();
                insert(p,mx);
                break;
            }
            case 2:
            {
                emp x=Delete(p);
                if(x.sal!=-1)
                    printf("Deleted item : %d - %s\n",x.id,x.name);
                break;
            }
            case 3: 
            	display(p,1,0);
            	break;
            case 4:
            	exit(0);
            default:
            	printf("Inappropriate choice entered...");
        }
    }while(ch);
}

/*  OUTPUT:
   ---------
PS C:\Users\Srinath\Desktop> gcc d.c -o a
PS C:\Users\Srinath\Desktop> ./a
Enter the Heap size:5
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....1
Enter Details:
ID:5

Name:ram

Salary:56000
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....1
Enter Details:
ID:4

Name:suresh

Salary:67000
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....1
Enter Details:
ID:3

Name:mohan

Salary:90000
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....1
Enter Details:
ID:2

Name:lakshman

Salary:80000
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....1
Enter Details:
ID:95

Name:rod

Salary:50000
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....3
5*ram*56000.00
  4*suresh*67000.00
    2*lakshman*80000.00
    95*rod*50000.00
  3*mohan*90000.00
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....2
Deleted item : 5 - ram
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....2
Deleted item : 95 - rod
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....3
4*suresh*67000.00
  2*lakshman*80000.00
  3*mohan*90000.00
Priority Queue:
1) Insert
2) Delete
3) Display
4) Exit
Enter Your Choice....4

*/