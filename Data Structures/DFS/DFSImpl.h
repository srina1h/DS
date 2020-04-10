void initializeStack(stack *ot,int x)
{
	ot->top=-1;
	ot->n=x;
}

int isfull(stack *ot)
{
	if(ot->top==ot->n-1)
		return(1);
	else
		return(0);
}

int isempty(stack *ot)
{
	if(ot->top==-1)
		return(1);
	else
		return(0);
}

void push(stack *ot,int x)
{
	if(isfull(ot))
	{
		printf("\n Stack is full....\n");	
	}
	else
	{
		ot->top+=1;
		ot->s[ot->top]=x;		
	}
}

int pop(stack *ot)
{
	int p=0;
	if(isempty(ot))
	{
		printf("\n Stack is empty \n");		
	}
	else
	{
		ot->top-=1;
		return p=ot->s[ot->top+1];	
	}
}

int peek(stack *ot)
{
	int p=0;
	if(isempty(ot))
	{
		printf("\n Stack is empty.....\n");		
	}
	else
		return ot->s[ot->top];
}

int size(stack *ot)
{
	int i=0;
	i=ot->top;
	return i;	
}

void disps(stack *ot)
{
	int j=0;
	if(ot->top>=0)
	{	
		printf("\n Stack : ");
		for(j=size(ot);j>=0;j--)
		{
			printf("%d ",ot->s[j]);
		}
	}
	else
	{
		printf("\n The stack is empty.....\n");
	}
}

void initialize(city *c,int x)
{
	c->nov=x;
}

void getdata(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{	
		printf(" Enter city name: ");
		scanf(" %[^\n]",c->cities[i]);
	}
}

void putdata(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{	
		printf("\n City: %s",c->cities[i]);
	}
}

int pos(city *c,char n[25])
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(strcmp(c->cities[i],n)==0)
			return(i);
	}
}

void create(city *c)
{
	int i,j,k,n;
	char x[50][50];
	printf("\n Checking connection: ");
	for(i=0;i<c->nov;i++)
	{
		printf("\n Edge count of %s : ",c->cities[i]);
		scanf(" %d",&n);
		if(n>0)
			printf(" Edges of %s :\n",c->cities[i]);
		for(j=0;j<n;j++)
		{
			printf(" Edge %d : ",j+1);
			scanf(" %[^\n]",x[j]);
			c->map[pos(c,c->cities[i])][pos(c,x[j])]=1;
		}					
	}	
}

void display(city *c)
{
	int i,j;
	printf("\n Adjacency Matrix:\n");
	for(i=0;i<c->nov;i++)
	{
		printf("\n %s\t",c->cities[i]);
		for(j=0;j<c->nov;j++)
		{
			printf(" %d ",c->map[i][j]);
		}
	}
	printf("\n");
}

int adjustunvisited(city *c,int x)
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(c->map[x][i]==1 && c->vis[i]==0)
			return(i);
	}
	return(-1);
}

int notvisited(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(c->vis[i]==0)
			return(i);
	}
	return(-1);
}

void DFS(city *c,int x)
{
	c->S=(stack*)malloc(sizeof(stack));
	initializeStack(c->S,c->nov);
	int i,j,z,uv,p;
	for(i=0;i<c->nov;i++)
		c->vis[i]=0;
	c->vis[x]=1;
	push(c->S,x);
	printf(" DFS path: %s ",c->cities[x]);
	while(!isempty(c->S))
	{
		z=peek(c->S);
		if((uv=adjustunvisited(c,z))!=-1)
		{
			c->vis[uv]=1;
			printf("%s ",c->cities[uv]);
			push(c->S,uv);
		}
		else
			p=pop(c->S);
	}
	printf("\n");
}

void DFSend(city *c,int x,int y)
{
	c->S=(stack*)malloc(sizeof(stack));
	initializeStack(c->S,c->nov);
	int i,j,z,uv,p;
	for(i=0;i<c->nov;i++)
		c->vis[i]=0;
	c->vis[x]=1;
	push(c->S,x);
	printf(" Actual path: ");
	while(!isempty(c->S))
	{
		z=peek(c->S);
		if((uv=adjustunvisited(c,z))!=-1)
		{
			c->vis[uv]=1;
			push(c->S,uv);
			if(uv==y)
				break;
		}
		else
			p=pop(c->S);
	}
}

int connect(city *c,int x,int y)
{
	DFSend(c,x,y);
	stack *X;
	X=(stack*)malloc(sizeof(stack));
	initializeStack(X,c->nov);
	while(!isempty(c->S))
		push(X,pop(c->S));
	while(!isempty(X))
	{
		printf("%s ",c->cities[pop(X)]);
	}
	printf("\n");
	if(c->vis[y]==1)
		return(1);
	else
		return(0); 
}