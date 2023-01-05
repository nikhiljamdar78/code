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
 
 //Search
NODE *search(NODE * root, int n)
{
	NODE *temp = root;
	while(temp != NULL)
	{
		if(temp->info==n)
		{
			printf("\t'%d'  Is Present In BST", n);
			return temp;
		}
		if(n < temp->info)
			temp=temp->left;
		else
			temp=temp->right;
	}
	 printf("\t>>'%d' IS Not Present In BST<<",n);
}
 
//INORDER
void inorder(NODE * root)
{
    NODE *temp = root;
    if(temp != NULL)
    {
    	inorder(temp->left);
    	printf("%d\t", temp->info);
    	inorder(temp->right);
    }
}
