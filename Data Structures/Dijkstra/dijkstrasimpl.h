void init(city *c,int x)
{
	c->nov=x;
}

void getdata(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{	
		printf(" City name : ");
		scanf(" %[^\n]",c->cities[i]);
	}
}

void putdata(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{	
		printf("\n City name : %s",c->cities[i]);
	}
}


int pos(city *c,char n[25])
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(strcmp(c->cities[i],n)==0)
			return i;
	}
}

void create(city *c)
{
	int i,j,k,n,d;
	char x[50][50];
	printf("\n Check connection : ");
	for(i=0;i<c->nov;i++)
	{
		printf("\n Edge count of %s : ",c->cities[i]);
		scanf(" %d",&n);
		if(n>0)
			printf(" Edges of %s :\n",c->cities[i]);
		for(j=0;j<n;j++)
		{
			printf(" Edge %d      : ",j+1);
			scanf(" %[^\n]",x[j]);
			printf(" Edge length : ");
			scanf("%d",&d);
			c->maplen[pos(c,c->cities[i])][pos(c,x[j])]=d;
			c->map[pos(c,c->cities[i])][pos(c,x[j])]=1;
		}					
	}	
}

void disp(city *c)
{
	int i,j;
	printf("\n Adjacency Matrix :\n");
	for(i=0;i<c->nov;i++)
	{
		printf("\n %-8s\t",c->cities[i]);
		for(j=0;j<c->nov;j++)
		{
			printf(" %-2d ",c->map[i][j]);
		}
	}
	printf("\n");
	printf("\n Distance Matrix :\n");
	for(i=0;i<c->nov;i++)
	{
		printf("\n %-8s\t",c->cities[i]);
		for(j=0;j<c->nov;j++)
		{
			printf(" %-2d ",c->maplen[i][j]);
		}
	}
	printf("\n");	
}

int adjacent(city *c,int x)
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(c->map[x][i]==1 && c->tempvis[i]==0)
		{
			c->tempvis[i]=1;
			return i;
		}
	}
	return -1;
}

int notvis(city *c)
{
	int i;
	for(i=0;i<c->nov;i++)
	{
		if(c->vis[i]==0)
			return i;
	}
	return -1;
}

void disptable(city *c)
{
	int i;
	printf("\n | V \t| K \t| D \t| P \t|\n");
	for(i=0;i<c->nov;i++)
	{
		if(c->dist[i]==INT_MAX)
			printf(" | %-3s \t| %-3d \t| %-3s \t| %-3s \t|\n",c->cities[i],c->vis[i],"Inf",c->path[i]);
		else		
			printf(" | %-3s \t| %-3d \t| %-3d \t| %-3s \t|\n",c->cities[i],c->vis[i],c->dist[i],c->path[i]);
	}
	printf("\n\n");	
}

int leastunvis(city *c)
{
	int i,pos=-1,min=1000;
	for(i=0;i<c->nov;i++)
	{
		if(c->vis[i]==0)
		{
			if(min>c->dist[i])
			{	
				min=c->dist[i];
				pos=i;
			}
		}
	}
	return pos;
}

void dijkstraTable(city *c,int x)
{
	int v,w,cvw,i;
	for(i=0;i<c->nov;i++)
	{
		c->vis[i]=0;
		c->dist[i]=INT_MAX;
		strcpy(c->path[i],"0");
	}
	c->dist[x]=0;
	printf("\n Initial Configuration \n");
	disptable(c);
	
	while(notvis(c)!=-1)
	{
		v=leastunvis(c);
		printf(" %s is known \n",c->cities[v]);
		c->vis[v]=1;
		for(i=0;i<c->nov;i++)
			c->tempvis[i]=0;

		while((w=adjacent(c,v))!=-1)
		{
			if(c->vis[w]==0)
			{
				if((c->dist[v]+c->maplen[v][w])<c->dist[w])
				{
					c->dist[w]=c->dist[v]+c->maplen[v][w];
					strcpy(c->path[w],c->cities[v]);
				}
			}
		}
		disptable(c);
	}
	printf("\n Final Configuration \n");
	disptable(c);
}

void dijkstraPath(city *c,int x)
{
	int v,w,cvw,i,t,d;
	for(i=0;i<c->nov;i++)
	{
		c->vis[i]=0;
		c->dist[i]=INT_MAX;
		strcpy(c->path[i],"0");
	}
	c->dist[x]=0;

	while(notvis(c)!=-1)
	{
		v=leastunvis(c);
		c->vis[v]=1;
		for(i=0;i<c->nov;i++)
			c->tempvis[i]=0;

		while((w=adjacent(c,v))!=-1)
		{
			if(c->vis[w]==0)
			{
				if((c->dist[v]+c->maplen[v][w])<c->dist[w])
				{
					c->dist[w]=c->dist[v]+c->maplen[v][w];
					strcpy(c->path[w],c->cities[v]);
				}
			}
		}
	}
	
	printf("\n Paths to %s",c->cities[x]);
	for(i=0;i<c->nov;i++)
	{	
		t=i;
		d=0;
		printf("\n\n From %s",c->cities[i]);
		printf("\n Path : %s",c->cities[i]);
		while(t!=x)
		{	
			printf("->%s",c->path[t]);
			t=pos(c,c->path[t]);
		}
		printf("\n Dist : %d",c->dist[i]);
	}
	printf("\n");
}