void initialize(stack *t)		
{
	(*t).top=-1;
	printf("\nenter the limit:");
	scanf("%d",&(t->limit));
}

void initialisen(stack *t)		
{
	(*t).top=-1;
	t->limit=100;
}

int isempty(stack *t)			
{
	if((*t).top==-1)
		return 1;
	else
		return 0;
}

int isfull(stack *t)			
{
	if((*t).top==(*t).limit-1)
		return 1;
	else
		return 0;
}

void Size(stack t)				
{
	printf("\nThe size of the given stack is %d",t.top+1);
}

void disp(stack t)				
{
	int i;
	for(i=0;i<=t.top;i++)
	{
		printf("\n%c",t.c[i]);
		if(i==t.top)
			printf(" <--");
	}
}

void push(stack *t,char x)			
{
	if(isfull(t))
		printf("\n The stack is full");
	else
	{
		(*t).top++;
		t->c[(*t).top]=x;
	}
}

int prec(char c) 				
{ 
    if(c == '^') 
    	return 3; 
    else if(c == '*' || c == '/') 
    	return 2; 
    else if(c == '+' || c == '-') 
    	return 1; 
    else
    	return -1; 
} 

char * infixtoPostfix(char *str, stack *s)		
{
	push(s,1);
	static char st[100];
	int j=0;
	for(int i=0;i<strlen(str);i++)
	{
		char x=*(str+i);
		if(x!='+'&&x!='-'&&x!='*'&&x!='/'&&x!=')'&&x!='('&&x!='^')	
		{
			st[j++]=x;
		}
		else if(x == '(') 
			push(s,'('); 
		else if(x == ')') 
        { 
            while(s->c[(*s).top] != 1 && s->c[(*s).top] != '(') 
            { 
                char c = pop(s); 
                st[j++]=c;  
            } 
            if(s->c[(*s).top] == '(') 
            { 
                char c = pop(s);    
            } 
        } 
		else
		{ 
            while(s->c[(*s).top] != 1 && prec(x) <= prec(s->c[(*s).top])) 
            { 
                char c = pop(s); 
                st[j++]=c;     
            } 
            push(s,x);
        } 
	}
	while(s->c[(*s).top] != 1) 
    { 
		char c = pop(s); 
        st[j++]=c;
    } 
	st[j++]=0;
	return st;		
}

char pop(stack *t)			
{
	if(isempty(t))
		return 0;
	else
	{
		char x=t->c[(*t).top];
		(*t).top--;
		return x;
	}
}

int evaluateExp(char *postfix, stack *s) 	
{   
    int i; 
    for(i=0;postfix[i];i++)  
    { 
        if (isdigit(postfix[i]))  		
            push(s, postfix[i] - '0');  
        else
        {  
            int val1 = pop(s);  
            int val2 = pop(s);  
            switch (postfix[i])  		
            {   
		        case '+': 
		        	push(s, val2 + val1); 
		        	break;  
		        case '-': 
		        	push(s, val2 - val1); 
		        	break;  
		        case '*': 
		        	push(s, val2 * val1); 
		        	break;  
		        case '/': 
		        	push(s, val2/val1); 
		        	break;  
            }  
        }  
    }  
    return pop(s);  
}

void initializeT(stackT *t)		
{
	(*t).top=-1;
	t->limit=100;
}

int isEmptyT(stackT *t)			
{
	if((*t).top==-1)
		return 1;
	else
		return 0;
}

int isFullT(stackT *t)			
{
	if((*t).top==(*t).limit-1)
		return 1;
	else
		return 0;
}

void pushT(stackT *t,node *x)			
{
	if(isFullT(t))
		printf("\n The stack is full");
	else
	{
		(*t).top++;
		t->c[(*t).top]=x;
	}
}

node* popT(stackT *t)			
{
	if(isEmptyT(t))
		return 0;
	else
	{
		node *x=t->c[(*t).top];	
		(*t).top--;
		return x;
	}
}

void createtree(expADT *d)
{
	initializeT(&d->t);
	int l=strlen(d->postfix);
	int i;
	for(i=0;i<l;i++)
	{
		if(isalnum(d->postfix[i]))
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->a=d->postfix[i];
			temp->right=NULL;
			temp->left=NULL;
			pushT(&d->t,temp);
		}
		else
		{
			node *temp=(node *)malloc(sizeof(node));
			temp->a=d->postfix[i];
			temp->right=popT(&d->t);
			temp->left=popT(&d->t);
			pushT(&d->t,temp);
		}
	}
	d->p=popT(&d->t);
}	
			
int evaluate(node *d)
{
	if(d->left==NULL && d->right==NULL)
	{
		return d->a-'0';
	}
	else
	{
		char op=d->a;
		int val1=evaluate(d->left);
		int val2=evaluate(d->right);
		switch (op)  		
        {   
        	case '+':
				return val2+val1; 
				break;  
            case '-': 
            	return val2-val1; 
            	break;  
            case '*': 
            	return val2*val1; 
            	break;  
            case '/': 
            	return (int)(val2/val1); 
            	break;  
        }  
	}
}

void display(node *p,int space)
{
	if(p==NULL)
		return;
	space+=10;
	display(p->right,space);
	printf("\n");
	for(int i=10;i<space;i++)
		printf(" ");
	printf("%c\n",p->a);
	display(p->left,space);
}













