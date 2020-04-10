
void initialize(node *head,node *tail)
{
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
}
	
void insertFront(node *head,node *tail,pis data)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->data = data; 
	if(head->next == tail)
	{
		ptr->prev = head;
		ptr->next = tail;
		head->next = ptr;
		tail->prev = ptr;
	}
	else 
	{	
		ptr->next = head->next;
		head->next->prev = ptr;
		ptr->prev = head;
		head->next = ptr;
	}
}

void insertEnd(node *head,node *tail,pis data)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->data = data;
	if(tail->prev == head)
	{
		ptr->prev = head;
		ptr->next = tail;
		head->next = ptr;
		tail->prev = ptr;
	}
	else
	{
		ptr->prev = tail->prev;
		tail->prev->next = ptr;
		ptr->next = tail;
		tail->prev = ptr;
	}
}

void insertPIN(node *head,node *tail,pis p,int pin)
{
	int flag = 1;
	node *temp;
	node *ptr;
	temp = (node*)malloc(sizeof(node));
	temp = head->next;
	while(temp)
	{
		if(temp->data.pin == pin)
		{
			flag = 0;
			break;
		}
		temp = temp->next;
	}
	if(flag)
		printf("\nPerson not found!");
	else
	{
		if(temp->next == tail)
			insertEnd(head,tail,p);
		else if(temp->prev == head)
			insertFront(head,tail,p);
		else
		{
			(temp->next)->prev = ptr;
			ptr->next = temp->next;
			temp->next = ptr;
			ptr->prev = temp;
		}
	}
}

node *locatePerson(node *head,node *tail,char *s)
{
	node *temp = head->next,*newhead,*newtail;
	newhead = (node*)malloc(sizeof(node));
	newtail = (node*)malloc(sizeof(node));
	initialize(newhead,newtail);
	while(temp)
	{
		if(strcmpi(temp->data.cityAdd,s) == 0)
			insertFront(newhead,newtail,temp->data);
		temp = temp->next;	
	}
	return newhead;
}

node *seniorPerson(node *head,node *tail)
{
	node *temp = head->next,*newhead,*newtail;
	newhead = (node*)malloc(sizeof(node));
	newtail = (node*)malloc(sizeof(node));
	initialize(newhead,newtail);
	while(temp)
	{
		if(temp->data.age >= 60)
			insertFront(newhead,newtail,temp->data);
		temp = temp->next;	
	}
	return newhead;
}

void display(node *head,node *tail)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	if(head->next == tail)
	{
		printf("\nThe list is empty !");
	}
	else
	{
		ptr = head;
		printf("\nPrinting straight: ");
		ptr = ptr->next;
		while(ptr != tail)
		{
			printf("\nName: ");
			printf("%s", ptr->data.name);
			printf("\nAge: ");
			printf("%d", ptr->data.age);
			printf("\nSex: ");
			printf("%c", ptr->data.sex);
			printf("\nCity Address: ");
			printf("%s", ptr->data.cityAdd);
			printf("\nStreet Address: ");
			printf("%s", ptr->data.streetAdd);
			printf("\nPIN: %d", ptr->data.pin);
			ptr = ptr->next;
		}
		ptr = tail;
		printf("\nPrinting in reverse: ");
		ptr = ptr->prev;
		while(ptr != head)
		{
			printf("\nName: ");
			printf("%s", ptr->data.name);
			printf("\nAge: ");
			printf("%d", ptr->data.age);
			printf("\nSex: ");
			printf("%c", ptr->data.sex);
			printf("\nCity Address: ");
			printf("%s", ptr->data.cityAdd);
			printf("\nStreet Address: ");
			printf("%s", ptr->data.streetAdd);
			printf("\nPIN: %d", ptr->data.pin);
			ptr = ptr->prev;
		}
	}
}

void displaySenior(node *head)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr = head->next;
		while(ptr->next != NULL)
		{
			printf("\nName: ");
			printf("%s", ptr->data.name);
			printf("\nAge: ");
			printf("%d", ptr->data.age);
			printf("\nSex: ");
			printf("%c", ptr->data.sex);
			printf("\nCity Address: ");
			printf("%s", ptr->data.cityAdd);
			printf("\nStreet Address: ");
			printf("%s", ptr->data.streetAdd);
			printf("\nPIN: %d", ptr->data.pin);
			ptr = ptr->next;
		}
}

void sort(node *head, node *tail)
{
	node *temp = head->next, *t, *tailTemp = tail->prev;
	pis t1;
	while(tailTemp !=  head->next){
		t = head->next;
		while(t != tailTemp){
			if(t->data.age > (t->next)->data.age){
				t1 = t->data;
				t->data = t->next->data;
				t->next->data = t1;
			}
			t = t->next;
		}
		tailTemp = tailTemp->prev;
	}
}

mf returnratio(node *head,node *tail)
{
	mf rat;
	rat.m = 0;
	rat.f = 0;
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr = head;
	ptr = ptr->next;
	while(ptr != tail)
	{
		if(ptr->data.sex == 'M')
			rat.m++;
		else if(ptr->data.sex == 'F')
			rat.f++;
		ptr=ptr->next;
	}
	rat.ratio = rat.m/rat.f;
	return(rat);
}
	
