void initialize(polyADT *p)
{
	p->next=NULL;
}

void input(int n,int v[],int e[],polyADT *p)
{
	polyADT *x=(polyADT *)malloc(sizeof(polyADT));
	int i;
	for(i=n-1;i>=0;i--)
	{
		polyADT *x=(polyADT *)malloc(sizeof(polyADT));
		x->t.val=v[i];
		x->t.exp=e[i];
		x->next=NULL;
		x->next=p->next;
		p->next=x;
	}
}
void print(polyADT *p)
{
	polyADT *temp;
	temp=p->next;
	int i;
	i=0;
	printf("the polynomail is:");
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->t.val,temp->t.exp);
		if(temp->next!=NULL)
			printf("+");
		temp=temp->next;
	
	}
}
void insertFront(polyADT *p,term x)
{
	polyADT *temp=(polyADT *)malloc(sizeof(polyADT));
	temp->t.val=x.val;
	temp->t.exp=x.exp;
	temp->next=p->next;
	p->next=temp;
	print(p);
}
void insertEnd(polyADT *p,term x)
{	
	polyADT *temp=(polyADT *)malloc(sizeof(polyADT));
	temp->t.val=x.val;
	temp->t.exp=x.exp;
	temp->next=NULL;
	polyADT *m;
	m=p;
	while((m->next)!=NULL)
		m=m->next;
	m->next=temp;
	
}
void insertAfterTerm(polyADT *p,term x,int e)
{	
	polyADT *temp=(polyADT *)malloc(sizeof(polyADT));
	temp->t.val=x.val;
	temp->t.exp=x.exp;
	polyADT *m;
	m=p->next;
	while(m->t.exp!=e)
		{
			m=m->next;
		}
	temp->next=m->next;
	m->next=temp;
	print(p);
}
void PolyAdd(polyADT *p1, polyADT *p2)
{
	polyADT *p3=(polyADT *)malloc(sizeof(polyADT));
	polyADT *temp=(polyADT *)malloc(sizeof(polyADT));
	polyADT *m,*n;
	initialize(p3);
	m=p1->next;
	n=p2->next;
	while(m!=NULL&&n!=NULL)
	{	
		if(m->t.exp>n->t.exp)
		{	
			insertEnd(p3,m->t);
			m=m->next;
		}
		else if(m->t.exp<n->t.exp)
		{	
			insertEnd(p3,n->t);
			n=n->next;
		}
		else
		{
			temp->t.val=m->t.val+n->t.val;
			temp->t.exp=m->t.exp;
			insertEnd(p3,temp->t);
			m=m->next;
			n=n->next;
		}
	}
	while(m!=NULL)
	{	
		insertEnd(p3,m->t);
		m=m->next;
	}
	while(n!=NULL)
	{
		insertEnd(p3,n->t);
		n=n->next;
	}
	print(p3);
}
void PolyMul(polyADT *p1, polyADT *p2)
{	
	polyADT *p3=(polyADT *)malloc(sizeof(polyADT));
	polyADT *temp=(polyADT *)malloc(sizeof(polyADT));
	polyADT *m,*n,*o;
	initialize(p3);
	m=p1->next;
	while(m!=NULL)
	{
		n=p2->next;
		while(n!=NULL)
		{	
			o=p3->next;
			temp->t.val=m->t.val*n->t.val;
			temp->t.exp=m->t.exp+n->t.exp;
			int flag;
			flag=0;
			while(o!=NULL)
			{	
				if(temp->t.exp==o->t.exp)
				{
					o->t.val+=temp->t.val;
					flag=1;
					break;
				}
				o=o->next;
			}
			if(flag==0)
				insertEnd(p3,temp->t);
			n=n->next;
		}
		m=m->next;
	}
	print(p3);
}

void PolyDeg(polyADT  *p)
{
		polyADT *n;
		n = p->next;
		int deg = n->t.exp;
		while(n!=NULL)
		{
			if(n->t.exp>deg)
					deg = n->t.exp;
			n = n->next;	
		}
		printf("\nThe degree of the polynomia is %d",deg);
}

int PolyEval(polyADT  *p)
{
		int x,sum=0;
		polyADT *n;
		n = p->next;
		printf("Enter value of x: ");
		scanf("%d",&x);
		while(n!=NULL)
		{
 			sum+=(n->t.val* pow(x,n->t.exp));
 			n = n->next;
 		}
		printf("\nThe equations has been evaulated to give the sum = %d",sum);
}

polyADT PolySimplify(polyADT  *p)
{	
	polyADT *temp = (polyADT *)malloc(sizeof(polyADT));
	polyADT *m,*n,*o;
	m=p->next;
	int flag=0;
	while(m!=NULL)
	{
		n=m->next;
		while(n!=NULL)
		{	
			if(m->t.exp==n->t.exp)
			{
				m->t.val+=n->t.val;
				flag=1;
				o->next=n->next;
			}
			o=n;
			n=n->next;
		}
		m=m->next;

	}
	print(p);
}