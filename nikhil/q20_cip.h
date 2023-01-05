typedef struct node
 {
    int info;
    struct node *left, *right;
 }NODE;

//CREATE
 NODE * create(NODE *root)
 {
    	NODE *nn, *temp;
    	int i, n, num;
    	printf("\nHow many nodes you want to inserted...?\t ");
    	scanf("%d",&n );
    	for(i=1; i<=n; i++)
    	{
    		nn=(NODE*)malloc(sizeof(NODE));
    		printf("Enter %d Element:\t",n);
    		scanf("%d",&num);
    		nn->info = num;
    		nn->left=nn->right=NULL;
    		if(root==NULL)
    			root=nn;
    			else
    			{
    				temp=root;
    				while(1)
    				{
    					if(nn->info < temp->info)
    						if(temp->left == NULL)
    						{
    							temp->left=nn;
    							break;
    						}
    						else
    							temp=temp->left;
    						else
    						if(temp->right == NULL)
    						{
    							temp->right=nn;
    							break;		
    						}
    						else
    							temp=temp->right;	
    				}//while
    			}//else
    	}//for	
    	return(root);
 }
 
//INSERT 
NODE * insert(NODE *root, int n)
{
    	NODE *temp, *nn;
    	nn = (NODE*)malloc(sizeof(NODE));
    	nn->left=nn->right=NULL;
    	nn->info=n;

    	if(root==NULL)
    	{
    		root=nn;
    		return root;
    	}
    	else
    	{
    		temp=root;
    		while(1)
    		{
    			if(n < temp->info)
    			{
    				if(temp->left==NULL)
    				{
    					temp->left=nn;
    					break;
    				}
    				else
    					temp=temp->left;
    			}
    			else
    				if(n > temp->info)
    				{
    					if(temp->right==NULL)
    					{
    						temp->right=nn;
    						break;
    					}
    					else
    						temp=temp->right;
    				}//if
    		}//while
    	}//else
    	return(root);
}

//POSTORDER
void postorder(NODE * root)
 {
    NODE *temp = root;
    if(temp != NULL)
    {
    	postorder(temp->left);
        postorder(temp->right);
        printf("%d\t", temp->info);
    }
 }
 
