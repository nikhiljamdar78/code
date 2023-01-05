#include<stdio.h>
#include<stdlib.h>

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

void recdfs(int m[10][10], int n, int v)
{
	int w;
	static int visited[20]={0};
	visited[v]=1;
	printf("v%d ",v+1);
	for(w=0; w<n; w++)
	{
		if((m[v][w] == 1) && (visited[w] == 0))
		recdfs(m, n, w);
	}
}
		
int main()
{
	int m[10][10], n,i;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	createmat(m,n);
	dismat(m,n);
	
	printf("\n\nThe Depth First Search Traversal  is:\t");
	recdfs(m,n,0);
}
