#include "postfixinterface.h"
#include "postfiximpl.h"

int checkprec(Stack *s,char c)
{
	if(s->top==-1)
		return 1;
	else if((c=='^')&&(s->a[s->top]!='^'))
		return 1;
	else if(((c=='*')||(c=='/'))&&((s->a[s->top]=='+')||(s->a[s->top]=='-')))
		return 1;
	else 
		return 0;
}

char *infixtopostfix(char s[50])
{
	char *postfix;
	postfix = (char*)malloc(50*sizeof(char));
	Stack S;
	initialize(&S);
	int i=0,k=0;
	char popped;
	int p;
	while(s[i]!='\0')
	{
		if(isdigit(s[i]))
		{
			postfix[k] = s[i];
			k++;
		}
		else
		{
			do
			{
				p = (checkprec(&S,s[i]));
				if(p == 1)
					push(&S,s[i]);
				else
				{
					popped = pop(&S);
					postfix[k] = popped;
					k++;
				}	
			}while(p!=1);
		}
		i++;
	}
	while(S.top != -1)
	{
		popped = pop(&S);
		postfix[k] = popped;
		k++;
	}
	postfix[k] = '\0';
	return(postfix);
} 

int evaluate(char post[20])
{	
	Stack s;
	initialize(&s);
	int i;
	for(i=0;i<strlen(post);i++)
	{	
		if(isdigit(post[i]))
			push(&s,post[i]);
		else
		{	
			int a = pop(&s)-'0';
			int b = pop(&s)-'0';
			if(post[i] == '*')
				push(&s,((a*b)+'0'));
			else if(post[i] == '/')
				push(&s,((b/a) + '0'));
			else if(post[i] == '+')
				push(&s,((a+b) + '0'));
			else if(post[i] == '-')
				push(&s,((b-a) + '0'));
			else if(post[i] == '^')
				push(&s,(pow(a,b)) + '0');
		}
	}
	int result = s.a[s.top]-'0';
	return(result);
}
	
	
void main()
{
	char *inf;
	inf = (char*)malloc(50*sizeof(char));
	printf("Enter the expression you wish to convert to postfix : ");
	scanf(" %s",inf);
	char *post;
	post = (char*)malloc(50*sizeof(char));
	post = infixtopostfix(inf);
	printf("The converted postfix expression is : ");
	printf(" %s",post);
	int evaluated = evaluate(post);
	printf("Evaluated postfix expression : %d",evaluated);
}

/*  OUTPUT:
   --------

 C:\Users\srina\Downloads>gcc postfixapplv2.c -o a

C:\Users\srina\Downloads>a
Enter the expression you wish to convert to postfix : 5-4/2*6+3

Value added to stack is : -
Value added to stack is : /
Value added to stack is : *
Value added to stack is : +The converted postfix expression is :  542/6*-3+
Value added to stack is : 5
Value added to stack is : 4
Value added to stack is : 2
Value added to stack is : 2
Value added to stack is : 6
Value added to stack is : <
Value added to stack is : )
Value added to stack is : 3
Value added to stack is : ,Evaluated postfix expression : -4
C:\Users\srina\Downloads>

*/
