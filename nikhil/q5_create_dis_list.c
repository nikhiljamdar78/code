#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct node
{
	int vertex;
	struct node * next;
}NODE;

NODE *list[10];

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
    
    void createlist( int m [10] [10], int n)
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
	NODE *temp, *nn;
	for(i=0; i<n; i++)
	{
		list[i] = NULL;
		for(j=0; j<n; j++)
		{
			if(m[i][j] == 1)
			{
				nn=(NODE *)malloc(sizeof(NODE));
				nn->vertex=j+1;
				nn->next=NULL;
				if(list[i] == NULL)
					list[i] = temp = nn;
				else
				{
					temp->next=nn;
					temp=nn;
				}	
			}
		}
	}
}

void dislist(int m[10] [10], int n)
{
	NODE *temp;
	int i;
	printf("\n\nThe Adjacency list is:");
	for(i=0; i<n; i++)
	{
		printf("\nv%d->",i+1);
		temp=list[i];
		while(temp)
		{
			printf("v%d ->",temp->vertex);
			temp = temp->next;
		}
		printf("NULL");
	}
}

void main()
{
	int m[10][10], n,w;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
		
	createlist(m,n);
	dislist(m,n);
	
}
