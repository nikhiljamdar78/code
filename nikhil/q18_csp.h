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
 
 //SUM OF EVEN NUMBERS
int sumEven(NODE *node1)
{
	int esum=0;
	if(node1 != NULL)
	{
		if((node1->info % 2 )== 0)
		esum += node1->info;
		esum += sumEven(node1->left);
		esum += sumEven(node1->right);
	}
	return esum;
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
 
