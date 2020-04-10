void display(node *t,int space)
{
	if(t==NULL)
		return;
	printf("\n");
	int i;
	for(i=0;i<space;i++)
		printf(" ");
    printf("Word: %s",t->data.word);
    printf("\n");
    for(i=0;i<space;i++)
		printf(" ");
    printf("Meaning: %s",t->data.meaning);
    display(t->left,space+10);
    display(t->right,space+10);
}

node* search(node *t,char n[])
{  		
   if(t==NULL)
   		return(NULL);
   if(strcmp(n,t->data.word) == 0)
   		return(t);
   if(strcmp(n,t->data.word) < 0)
   		return(search(t->left,n));
   if(strcmp(n,t->data.word) > 0)
   		return(search(t->right,n));
}

static int height (node *t)
{
	if(t==NULL)
		return(-1);
	else
		return(t->height);
}

node* insert(node*t,dict d)
{
	int hdiff;
	if(t==NULL)
	{
		t=(node*)malloc(sizeof(node));
		t->data=d;		
		t->height=0;
		t->left=t->right=NULL;	
	}
	else if(strcmp(d.word,t->data.word) < 0)
	{
		t->left=insert(t->left,d);
		hdiff=abs(height(t->left)-height(t->right));
		if(hdiff ==2)
			if(strcmp(d.word,(t->left)->data.word) < 0)
				t=singlerotatewithleft(t);
			else
				t=doublerotatewithleft(t);
	}
	else if(strcmp(d.word,t->data.word) > 0)
	{
		t->right=insert(t->right,d);
		hdiff=abs(height(t->left)-height(t->right));
		if(hdiff== 2)
			if(strcmp(d.word,(t->right)->data.word) > 0)
				t=singlerotatewithright(t);
			else
				t=doublerotatewithright(t);
	}
	t->height=max(height(t->left),height(t->right))+1;
	return(t);
}	

node* singlerotatewithleft(node *k2)
{
	node *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),k2-> height)+1;

	return(k1);
}

node* singlerotatewithright(node *k2)
{
	node *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;

	k2->height=max(height(k2->left),height(k2->right))+1;
	k1->height=max(height(k1->left),k2-> height)+1;

	return(k1);
}

node* doublerotatewithleft(node *k3)
{ 

	k3->left=singlerotatewithright(k3->left);

	return(singlerotatewithleft(k3));
}

node* doublerotatewithright(node *k3)
{
	k3->right = singlerotatewithleft(k3->right);
	return(singlerotatewithright(k3));
}
