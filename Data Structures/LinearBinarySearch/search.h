typedef struct numADT
{
	int a[50];
	int size;
}numADT;


numADT *init()
{
	numADT *t=malloc(sizeof(numADT));
	t->size=0;
	return t;
}

void insert( numADT *N, int arr[], int n)
{
	int j=0;
	for(int i=N->size;i<N->size+n;i++)
	{
		N->a[i]=arr[j++];
	}
	N->size+=n;
}


void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		swap(&arr[min_idx], &arr[i]); 
	} 
} 


int bSearch(numADT *N, int x) 
{ 
	int r=N->size-1,l=0,mid;
	selSort(N->a,N->size);
	while (r >= l) { 
		mid=(l+r)/ 2; 

		if (N->a[mid] == x) 
			return mid; 

		else if (N->a[mid] > x) 
			r=mid-1; 
		else
			l=mid+1;	
	} 

	return -1; 
} 

int lSearch(numADT *N, int x) 
{ 
	for (int i = 0; i < N->size; i++) 
		if (N->a[i] == x) 
			return i; 
	return -1; 
} 

void display(numADT *N)
{
	printf("\nArray elements are:\n ");
	for(int i=0;i<N->size;i++)
	{
		printf("%d ",N->a[i]);
	}
}

