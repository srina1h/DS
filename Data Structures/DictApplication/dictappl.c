#include "dictif.h"
#include "dictimpl.h"

void main()
{
	
	node *t,*tmp;
	dict p;
	t=NULL;
	//t = (node*)malloc(sizeof(node));
	int ch=23;
	char n[30];
	while(ch!=4)
	{
		printf("\n Dictionary operations: ");
		printf("\n ------ ---- ------------");
		printf("\n1.Insert word \n2.Search word \n3.Display hierarchially\n4.Exit ");
		printf("\nEnter your choice..");
		scanf(" %d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter word details: ");
				printf("Enter word: ");
				scanf(" %[^\n]",p.word);
				printf("Enter meaning: ");
				scanf(" %[^\n]",p.meaning);
				t = insert(t,p);
				break;
			case 2:
				printf("Enter word: ");
				scanf(" %[^\n]",n);
				tmp = search(t,n);
				printf("Word details:");
				printf("\nWord: %s",tmp->data.word);
				printf("\nMeaning: %s",tmp->data.meaning);
				break;
			case 3:
				display(t,0);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid input");
		}
	}
}

/* OUTPUT:
  ---------
  
cs1205@jtl-29:~/Desktop/programs/AVL$ gcc dictappl.c -o a
cs1205@jtl-29:~/Desktop/programs/AVL$ ./a

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..1
Enter word details: Enter word: apple
Enter meaning: fruit

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..1
Enter word details: Enter word: mechanic
Enter meaning: fixer

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..1
Enter word details: Enter word: car
Enter meaning: automobile

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..1
Enter word details: Enter word: computer
Enter meaning: processing

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..1
Enter word details: Enter word: fan
Enter meaning: blower

 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..3

Word: car
Meaning: automobile
          Word: apple
          Meaning: fruit
          Word: fan
          Meaning: blower
                    Word: computer
                    Meaning: processing
                    Word: mechanic
                    Meaning: fixer
 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..2
Enter word: apple
Word details:
Word: apple
Meaning: fruit
 Dictionary operations: 
 ------ ---- ------------
1.Insert word 
2.Search word 
3.Display hierarchially
4.Exit 
Enter your choice..4
*/

