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


void shellSort(numADT *N) 
{ 
	for (int gap = N->size/2; gap > 0; gap /= 2) 
	{ 
		for (int i = gap; i < N->size; i += 1) 
		{ 
			int temp = N->a[i]; 

			int j;			 
			for (j = i; j >= gap && N->a[j - gap] > temp; j -= gap) 
				N->a[j] = N->a[j - gap]; 
			
			N->a[j] = temp; 
		} 
	} 
} 

void selSort(numADT *N) 
{ 
	int i, j, min_idx; 

	for (i = 0; i < N->size-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < N->size; j++) 
			if (N->a[j] < N->a[min_idx]) 
				min_idx = j; 

		int temp = N->a[min_idx]; 
		N->a[min_idx]=N->a[i];
		N->a[i]=temp; 
	} 
} 


void display(numADT *N)
{
	printf("\nArray elements are:\n ");
	for(int i=0;i<N->size;i++)
	{
		printf("%d ",N->a[i]);
	}
}

