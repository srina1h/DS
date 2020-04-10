#include "PlayerInfoif.h"
#include "PlayerInfoimpl.h"

void main()
{
	node *t,*tmp;
	player p;
	t=NULL;
	//t = (node*)malloc(sizeof(node));
	int ch=23;
	while(ch!=8)
	{
		printf("\n Player info operations: ");
		printf("\n ------ ---- ------------");
		printf("\n1.Insert Player \n2.Delete Player \n3.Search Player \n4.Display hierarchially \n5.Display inorder \n6.Display preorder \n7.Display postorder \n8.Exit ");
		printf("\nEnter your choice..");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter player details: ");
				printf("Enter name: ");
				scanf(" %[^\n]",p.name);
				printf("Enter role: ");
				scanf(" %[^\n]",p.role);
				printf("Enter run rate: ");
				scanf(" %f",&p.rr);
				t = insert(t,p);
				break;
			case 2:
				printf("Enter player name: ");
				char n[30];
				scanf(" %[^\n]",n);
				t = delete(t,n);
				break;
			case 3:
				printf("Enter player name: ");
				scanf(" %[^\n]",n);
				tmp = search(t,n);
				printf("Player details:");
				printf("\nName: %s",tmp->data.name);
				printf("\nRole: %s",tmp->data.role);
				printf("\nRun rate: %f",tmp->data.rr);
				break;
			case 4:
				/*printf("Enter spacing: ");
				int s;
				scanf(" %d",&s);*/
				display(t,0);
				break;
			case 5:
				inorder(t);
				break;
			case 6:
				preorder(t);
				break;
			case 7:
				postorder(t);
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid input");
		}
	}
}

/*  OUTPUT:
   --------
 
cs1205@jtl-29:~/Desktop/programs/BST$ gcc PlayerInfoappl.c -o a
cs1205@jtl-29:~/Desktop/programs/BST$ ./a

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..1
Enter player details: Enter name: Dhoni 
Enter role: wickets
Enter run rate: 9.5

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..1
Enter player details: Enter name: Rohit
Enter role: batsman
Enter run rate: 7.8

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..1
Enter player details: Enter name: Raina
Enter role: batsman
Enter run rate: 6.8

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..1
Enter player details: Enter name: Bumrah
Enter role: bowler
Enter run rate: 3.0

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..1
Enter player details: Enter name: Bhuvaneshwar
Enter role: bowler
Enter run rate: 2.0

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..4

Dhoni
          Bumrah
                    Bhuvaneshwar
          Rohit
                    Raina
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..2
Enter player name: Raina

 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..3
Enter player name: Bumrah
Player details:
Name: Bumrah
Role: bowler
Run rate: 3.000000
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..5

 Player : Bhuvaneshwar
 Player : Bumrah
 Player : Dhoni
 Player : Rohit
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..6

 Player : Dhoni
 Player : Bumrah
 Player : Bhuvaneshwar
 Player : Rohit
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..7

 Player : Bhuvaneshwar
 Player : Bumrah
 Player : Rohit
 Player : Dhoni
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..4

Dhoni
          Bumrah
                    Bhuvaneshwar
          Rohit
 Player info operations: 
 ------ ---- ------------
1.Insert Player 
2.Delete Player 
3.Search Player 
4.Display hierarchially 
5.Display inorder 
6.Display preorder 
7.Display postorder 
8.Exit 
Enter your choice..8

*/
				
