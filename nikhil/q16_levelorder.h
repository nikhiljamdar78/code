  #define MAXSIZE 20
    typedef struct node
    {
    	int info;
    	struct node *left, *right;
    }NODE;

    					//QUEUE FUNCTIONS
    typedef struct
    {
    	NODE *data[MAXSIZE];
    	int front, rear;
    }QUEUE;

    void initq(QUEUE *pq)
    {
    	pq->front = pq->rear = -1;
    }

    void addq(QUEUE *pq, NODE *treenode)
    {
    	pq->data[++pq->rear] = treenode;
    }

    NODE* removeq(QUEUE *pq)
    {
    	return pq->data[++pq->front];
    }

    int isempty(QUEUE *pq)
    {
    	return (pq->front == pq->rear);
    }

    int isfull(QUEUE *pq)
    {
    	return(pq->rear == MAXSIZE-1);
    }



    					//TREE FUNCTION
    NODE * createbst(NODE *root)
    {
    	NODE *newnode, *temp, *parent;
    	int i, n, num;
    	printf("\nHow many nodes you want to enter?\t");
    	scanf("%d", &n);
    	printf("Enter the %d elements:\t", n);
    	for(i=1; i<=n; i++)
    	{
    		newnode = (NODE*)malloc(sizeof (NODE));
    		scanf("%d", &num);
    		newnode->info=num;
    		newnode->left = newnode->right = NULL;
    		if(root == NULL)
    		{
    			root = newnode;
    			continue;
    		}
    		temp = root;
    		while(temp != NULL)
    		{
    			parent = temp;
    			if(num < temp->info)
    				temp = temp->left;
    			else
    				temp = temp->right;	
    		}
    		if(num < parent->info)
    			parent->left = newnode;
    		else
    			parent->right = newnode;			
    	}	
    	return(root);
    }

//DISPLAY 
void display(NODE *root)
{
	NODE *temp=root;
	if(temp != NULL)
	{
		printf("\t%d",temp->info);
		display(temp->left);
		display(temp->right);
	}
}

//Level Order
    void levelorder(NODE *root)
    {
    	int i, level=0;
    	NODE *temp, *marker=NULL;
    	QUEUE q;
    	initq(&q);
    	addq(&q, root);
    	addq(&q, marker);
    	printf("\nLevel %d --->\t", level);
    	while(!isempty(&q))
    	{
    		temp = removeq(&q);
    		if(temp == marker)
    		{
    			level++;
    			if(!isempty(&q))
    			{
    				addq(&q, marker);
    				printf("\nLevel %d --->\t", level);
    			}
    		}
    		else
    		{
    			printf("%d\t", temp->info);
    			if(temp->left)
    				addq(&q, temp->left);
    			if(temp->right)
    				addq(&q, temp->right);
    		}
    	}
    }


