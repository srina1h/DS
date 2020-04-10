void initialize(Stack *S)
{
	S->top=-1;
	S->limit = 50;
}

int isFull(Stack *S)
{
	if(S->top==S->limit-1)
		return(1);
	else
		return(0);
}

int isEmpty(Stack *S)
{
	if(S->top==-1)
		return(1);
	else
		return(0);
}	

void push(Stack *S,char x)
{
	if(isFull(S))
		printf("\nStack overflow..");
	else 
	{
		S->top++;
		S->a[S->top]=x;
		printf("\nValue added to stack is : %c",x);
	}
}

char pop(Stack *S)
{
	if(isEmpty(S))
		printf("\nStack underflow..");
	else
	{
		S->top--;
		return(S->a[S->top+1]);
	}
}

void display(Stack *S)
{
	int i;
	if(isEmpty(S))
		printf("\nStack underflow..");
	else
	{
		printf("\n Stack items are: ");
		i=S->top;
		while(i>=0)
		{
			printf("\n %c",S->a[i]);
			i--;
		}
	}
}

void size(Stack *S)
{
	printf("\n Size of stack is: %d",S->top+1);
}

