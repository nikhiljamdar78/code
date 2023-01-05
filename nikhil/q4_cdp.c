//MAIN FILE
#include<stdio.h>
#include<stdlib.h>
#include "q4_cdp.h"

NODE * create(NODE *root);
void preorder(NODE * root);
NODE * deletebst(NODE *root, int n);

void main()
{
	NODE *root=NULL;
	int n, num,choice;
	
	printf("\t\t\t>>First Create BST<<\n");
        		
    root = create(root);
    
    do
	{
		printf("\n\n1.Preoder");
		printf("\n2.Delete");
		printf("\n Enter your Choice:\t");
        scanf("%d",&choice);
        
        switch(choice)
		{
			case 1:   	//PREORDER
						printf("\nPerorder traversal is:\t"); 
       					preorder(root);
						break;
						
			case 2:  	//DELETE
						printf("\n\nEnter Element you want to delete:\t");
    					scanf("%d",&n);
						root = deletebst(root,n);
						break;
						
			case 3 :	//EXIT
						printf("\t\t>>BYE<<");
						break;				
						
			default: printf("\t>>ENTER RIGHT CHOICE<<");		
           
		}	
	}while(choice!=3);
}										
