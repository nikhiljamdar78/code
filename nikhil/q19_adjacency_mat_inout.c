#include<stdio.h>
#include<stdlib.h>

void createmat(int m[10] [10], int n)
{
	int i, j;
	for(i=0; i<n; i++)
		for(j=0;j<n; j++)
		{
			m[i] [j] = 0;
			if(i != j)
			{
				printf("Is there an edge between %d->%d (1/0) :",i+1, j+1);
				scanf("%d", &m[i][j]);
			}
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


void inout(int m[10] [10], int n)
{
	int sumin, sumout, v, i, j;
	printf("\n\nVertex  Indegree    Outdegree   Total Degree \n");
	for(v=0; v<n; v++)
	{
		sumin = sumout = 0;
		for(i=0; i<n; i++)
		{
			sumin = sumin + m[i][v]; //sum of column v
			sumout = sumout + m[v][i]; //sum of row v
			
		}
		printf("  %d\t   %d\t\t%d\t   %d\n", v+1, sumin, sumout, sumin+sumout);
	}
}

void main()
{
	int m[10][10], n,i;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	
	createmat(m,n);
	dismat(m,n);
	
	inout(m,n);
}
