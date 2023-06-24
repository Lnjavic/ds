//IMPLEMENTATION OF A GRAPH ADT USING ADJACENCY LIST
#include<stdio.h>
#include<stdlib.h>

struct adjlistnode{
	int dest;
	struct adjlistnode * next;
};

struct adjlist{
	struct adjlistnode * head;
};

struct graph{
	int v;
	struct adjlist * array;
};

struct adjlistnode * newAdjlistnode(int dest)
{
	struct adjlistnode * newnode = (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
	newnode->dest = dest;
	newnode->next = NULL;
	return newnode;
}

struct graph * createGraph(int v)
{
	struct graph * newgraph = (struct graph*)malloc(sizeof(struct graph));
	newgraph->array = (struct adjlist*)malloc(v*sizeof(struct adjlist));
	newgraph->v = v;

	for(int a = 0;a<v;a++)
	{
		newgraph->array[a].head = NULL;
	}

	return newgraph;
}

void addEdge(struct graph * g,int src,int dest)
{
	struct adjlistnode * newnode = newAdjlistnode(dest);
	struct adjlistnode * check = NULL;

	if(g->array[src].head == NULL){
		newnode->next = g->array[src].head;
		g->array[src].head = newnode;
	}else{
		check = g->array[src].head;
		while(check->next != NULL){
			check = check->next;
		}

		check->next = newnode;
	}
}

void printGraph(struct graph * g)
{
	int i;
	for(i = 0; i<g->v;++i)
	{
		struct adjlistnode * pcrawl = g->array[i].head;
		printf("\n");
		while(pcrawl){
			printf("%d->", pcrawl->dest);
			pcrawl = pcrawl->next;
		}
	}
}

int main(){
	struct graph * g = createGraph(5);
	addEdge(g,0,1);
	addEdge(g,3,2);
	addEdge(g,0,2);
	printf("%d\n",g->v );
	printGraph(g);
	return 0;
}
