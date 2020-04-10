node* insert(node* t,player p)
{
	if(t == NULL)
	{
		t = (node*)malloc(sizeof(node));
		t->left = NULL;
		t->right = NULL;
		t->data = p;
	}
	if(strcmp(p.name,t->data.name) > 0)
		t->right = insert(t->right,p);
	if(strcmp(p.name,t->data.name) < 0)
		t->left = insert(t->left,p);
	return(t);
}

node* search(node *t,char n[])
{  		
   if(t==NULL)
   		return(NULL);
   if(strcmp(n,t->data.name) == 0)
   		return(t);
   if(strcmp(n,t->data.name) < 0)
   		return(search(t->left,n));
   if(strcmp(n,t->data.name) > 0)
   		return(search(t->right,n));
}
	
node* findmin(node *t)
{   	
    node* tmp = t; 
    while (tmp && tmp->left != NULL) 
        tmp = tmp->left; 
    return(tmp);   
}		

node* findmax(node *t)
{  
   if(t==NULL)
   		printf("Tree empty"); 
   while(t->right!=NULL)
   		return(findmax(t->right));
   //if(t->right==NULL)
   // printf("\n Maximum in the tree = %d",t->data);
}

/*
void display(node *t, int space) 
{ 
	int setline = 5,i;
    if(t == NULL) 
    	return;
    space += setline; 
    display(t->right, space); 
    printf("\n"); 
    for(i=setline;i < space;i++) 
        printf(" "); 
    printf("%s\n", t->data.name);  
    display(t->left, space); 
}
*/

void display(node *t,int space)
{
	if(t==NULL)
		return;
	printf("\n");
	int i;
	for(i=0;i<space;i++)
		printf(" ");
    printf("%s",t->data.name);
    display(t->left,space+10);
    display(t->right,space+10);
}



node* delete(node *t,char n[])
{
    if (t == NULL)
    	return(t); 
    if (strcmp(n,t->data.name) < 0) 
        t->left = delete(t->left,n); 
    else if (strcmp(n,t->data.name) > 0) 
        t->right = delete(t->right,n); 
    else
    { 
        if (t->left == NULL) 
        { 
            node *temp = t->right; 
            free(t); 
            return(temp); 
        } 
        else if (t->right == NULL) 
        { 
            node *temp = t->left; 
            free(t); 
            return(temp); 
        } 
        node* temp = findmin(t->right); 
        t->data = temp->data; 
        t->right = delete(t->right, temp->data.name); 
    } 
    return(t); 
}

void inorder(node *t)
{
	if(t!=NULL){
    inorder(t->left);
    printf("\n Player : %s",t->data.name);
    inorder(t->right);
    }
}

void preorder(node *t)
{
	if(t==NULL)
		return;
    printf("\n Player : %s",t->data.name);
    preorder(t->left);
    preorder(t->right);
}

void postorder(node *t)
{
	if(t==NULL)
		return;
    postorder(t->left);
    preorder(t->right);
    printf("\n Player : %s",t->data.name);
}


    
     
     
