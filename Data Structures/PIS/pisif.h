typedef struct pis
{
	char name[30];
	int age;
	char sex;
	int pin;
	char cityAdd[50];
	char streetAdd[50];
}pis;
	
typedef struct node
{
	struct pis data;
	struct node *next;
	struct node *prev;
}node;

typedef struct mf
{
	float m;
	float f;
	float ratio;
}mf;

void insertfront(node *head,node *tail,pis data);
void display(node *head,node *tail);
void initialize(node *head,node *tail);
mf returnratio(node *head,node *tail);
void sort(node *head, node *tail);
node *locatePerson(node *head,node *tail,char *s);
node *seniorPerson(node *head,node *tail);
void insertPIN(node *head,node *tail,pis p,int pin);
void insertEnd(node *head,node *tail,pis data);
