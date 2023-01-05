#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

  typedef struct 
    {
    	int front, rear;
    	int info[MAXSIZE];
    }QUEUE;
    
    void addq(QUEUE *pq, int n)
    {
    	pq->info[++pq->rear] = n;
    }

    void initq(QUEUE *pq)
    {
    	pq->front = pq->rear = -1;
    }


    int removeq(QUEUE *pq)
    {
    	return pq->info[++pq->front];
    }

    int isempty(QUEUE *pq)
    {
    	return (pq->front == pq->rear);
    }

void createmat(int m[10] [10], int n)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=0;j<n; j++)
		{
			m[i] [j] = 0;
			printf("Is there an edge between %d->%d (1/0) :",i+1, j+1);
			scanf("%d", &m[i][j]);

		}
}

void dismat( int m[10][10], int n)
{
	int i, j;
	printf("\n The Adjacency Matrix is:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		printf("\t%d", m[i] [j]);
		printf("\n");
	}
}

void bfs(int m[10][10], int n)
{
	int  v, w;
	int visited[20] = {0};
	QUEUE q;
	initq(&q);
	v=0; //starting vertex is 0
	visited[v]=1;
	addq(&q,v);
	while(!isempty(&q))
	{
		v=removeq(&q);
		printf("v%d ",v+1);
		for(w=0; w<n; w++)
			if((m[v][w] == 1) && (visited[w] == 0) )
			{
				addq(&q, w);
				visited[w] = 1;
			}
	}
}
		
int main()
{
	int m[10][10], n,i;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	createmat(m,n);
	dismat(m,n);
	
	printf("\n\nThe Breadth First Traversal is:\t");
	bfs(m,n);
}
