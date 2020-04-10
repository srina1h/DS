int isFull(Queue *Q)         
{
	if(Q->rear==Q->cap-1)
		return(1);
	return(0);
}

int isEmpty(Queue *Q)
{
	if(Q->front==-1)
		return(1);
	return(0);
}

void create(cityADT *C, int cities)   
{
	int i,j;
	C->n=cities;
	printf("\nEnter the names of cities: \n");
	for(i=0;i<C->n;i++)
	{
		printf("\nCity %d: ",i+1);
		scanf(" %[^\n]",C->data[i].city);
		C->data[i].visit=0;
	} 
	printf("\nGive connections between cities: 1 if Yes and 0 if No");
	for(i=0;i<cities;i++)
	{
		for(j=0;j<cities;j++)
		{
			int con=0;
			if(i!=j)
			{ 
				printf("\n Is there link between %s and %s :",C->data[i].city,C->data[j].city);
				scanf(" %d",&con);
			}
		C->adj[i][j]=con;
		}
	}
}

void display(cityADT *C)
{
	int i,j;
	int n = C->n;
	printf("The adjacency matrix is : \n\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",C->adj[i][j]);
	}
}

void enqueue(Queue *Q,char x[])
{
	if(isFull(Q))
		printf("\nQueue is full");
	else
	{
		if(Q->front==-1)
			Q->front++;
		Q->size++;
		strcpy(Q->data[++Q->rear],x);
	}
}

char* dequeue(Queue *Q)
{
	char *temp=NULL;
	if(isEmpty(Q))
		printf("Queue is empty");
	else
	{
		temp=(char*)malloc(sizeof(100));
		strcpy(temp,Q->data[Q->front]);
		Q->size--;
		if(Q->front==Q->rear)
			Q->front=Q->rear=-1;
		else
			Q->front++;
	}
	return temp;
}

int checkVisit(cityADT *C)
{
	int i;
	for( i=0;i<C->n;i++)
		if(C->data[i].visit==0)
			return(1);
	return(0);
}

void BFS( cityADT *C)
{
	Queue Q;
	Q.front=Q.rear=-1;
	Q.cap=C->n;
	Q.size=0;
	int i=0,j,k;
	while(checkVisit(C))
	{                	
		for(j=0;j<C->n;j++)
			if(C->data[j].visit==0)
			{
				i=j;
				break;
			}		
		printf("\n %s \n",C->data[i].city);
		C->data[i].visit=1;
		enqueue(&Q,C->data[i].city);
		while(Q.size)
		{           
			char *temp=NULL;
			temp=(char*)malloc(sizeof(100));
			strcpy(temp,dequeue(&Q));
			int b=0;
			for( k=0;k<C->n;k++)
				if(!strcmp(temp,C->data[k].city))
				{
					b=k;  
					break;
				}
			int a;
			for( a=0;a<C->n;a++)
			{
				if(C->adj[b][a])
				{      
					if(C->data[a].visit==0)
					{  
						printf("\n %s \n",C->data[a].city);
						C->data[a].visit=1;
						enqueue(&Q,C->data[a].city);
					}
				}
			}
		}
	}
}

int connect(cityADT *C, char source[], char dest[])
{
	int i,j,flag,k,l,b;
  	for(k=0;k<C->n;k++)
		if(!strcmp(source,C->data[k].city))
		{
			i=k;                         
			break;
		}
  	for(l=0;l<C->n;l++)
		if(!strcmp(dest,C->data[l].city))
		{
			j=l;               
			break;
		}
    if(C->adj[i][j])
		return(1);             
    else
    {
		flag=0;
		for(b=0;b<C->n;b++) 
			if(C->adj[i][b])        
				flag += connect(C,C->data[b].city,dest);
		if(flag>0)
			return(1);
		else
			return(0); 
	}
}
