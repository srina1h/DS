#define max 50

typedef struct cityADT
{
	int nov;
	char cities[100][100];
	int map[100][100];
	int maplen[100][100];
	int vis[100];
	int tempvis[100];
	int dist[100];
	char path[100][100];
}city;

void init(city *c,int x);
void getdata(city *c);
void putdata(city *c);
int pos(city *c,char n[25]);
void create(city *c);
void disp(city *c);
int adjacent(city *c,int x);
int notvis(city *c);
void disptable(city *c);
void dijkstraTable(city *c,int x);
void dijkstraPath(city *c,int x);