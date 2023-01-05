#include<stdio.h>
#include<stdlib.h>

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

//Count Leaf Node
int Leaf_count(NODE *root)
{
	static int count=0;
	NODE *temp=root;
	if(temp != NULL)
	{
		if(temp->left==NULL && temp->right==NULL)
		count++;
		Leaf_count(temp->left);
		Leaf_count(temp->right);
	}
	return (count);
}

int main()
{
	NODE *root=NULL;
    int n, num;
    printf("\t\t\t>>First Create BST<<\n");
        	
    //CREATE	
    root = create(root);
    
    	//LEAF NODE
		num=Leaf_count(root);
		printf("\n Total Number of Leaf Nodes In BST:\t%d",num);
}
