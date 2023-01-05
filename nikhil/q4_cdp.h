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
 
 //PERODER
void preorder(NODE * root)
{
   	NODE *temp = root;
   	if(temp != NULL)
   	{
		printf("%d\t", temp->info);
    	preorder(temp->left);
    	preorder(temp->right);
	}
}

//Delete 
 NODE * deletebst(NODE *root, int n)
 {
    	NODE * temp = root;
		NODE * prev = NULL;
	
	while(temp != NULL && temp->info != n)
	{
		prev = temp;
		if(n < temp->info)
			temp = temp->left;
		else
			temp = temp->right;	
	}
	
	if(temp==NULL)
	{
		printf("\t'%d' Not Found In BST\n",n);
		return root;
	}
	
	if(temp->left == NULL || temp->right == NULL)
	{
		NODE *nn;
		if(temp->left == NULL)
			nn = temp->right;
		else
			nn = temp->left;
		
		if(prev == NULL)
			return nn;		
			
		if(temp == prev->left)
			prev->left = nn;
		else
			prev->right = nn;
		
		free(temp);			
	}
	else
	{
		NODE * p = NULL;
		NODE * temp1;
		
		temp1 = temp->right;
		while(temp1->left != NULL)
		{
			p = temp1;
			temp1 = temp1->left;
		}
		if(p != NULL)
			p->left = temp1->right;
		else
			temp->right = temp1->right;	
		
		temp->info = temp1->info;
		free(temp1);	
	}
	return root;
}
