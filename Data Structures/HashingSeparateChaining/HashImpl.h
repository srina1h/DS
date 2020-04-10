typedef struct Node
{	
	int v;
	struct Node *ptr;    
}Node;


typedef struct Hash
{
	int size;
	Node *arr[20];
}Hash;

Hash *init(int s)
{
	Hash *t=(Hash *)malloc(sizeof(Hash));
	t->size=s;
	for(int i=0;i<s;i++)
	{
		t->arr[i]=malloc(sizeof(Node));
		t->arr[i]->ptr=NULL;
	}
	return t;
}

Node *insList(Node *N,int x)
{
	Node *n=malloc(sizeof(Node));
	n->ptr=N->ptr;
	n->v=x;
	N->ptr=n;
	return N;
}

void insert(Hash *H, int x)
{
	H->arr[x%H->size]=insList(H->arr[x%H->size],x);
}


int serNode(Node *N,int x)
{
	Node *t=N;
	while(t)
	{
		if(t->v==x)
			return 1;
		t=t->ptr;
	}
	return 0;
} 

int search(Hash *H,int x)
{
	return serNode(H->arr[x%H->size],x);
}

void display(Hash *H)
{
	Node *n;
	printf("\nHash Table: ");
	for(int i=0;i<H->size;i++)
	{
		printf("\n%d - ", i+1 );
		n=H->arr[i]->ptr;
		while(n)
		{
			printf("%d", n->v);
			if(n->ptr)
				printf("->");
			n=n->ptr;
		}
	}
}


