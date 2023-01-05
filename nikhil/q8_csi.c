//MAIN FILE
#include<stdio.h>
#include<stdlib.h>
#include "q8_csi.h"

NODE * create(NODE *root);
void preorder(NODE * root);
int sumOdd(NODE *node);

void main()
{
	NODE *root=NULL;
	int n,choice;
	
	printf("\t\t\t>>First Create BST<<\n");
        		
    root = create(root);
    
    do
	{
		printf("\n\n1.Search");
		printf("\n2.Inorder");
		printf("\n Enter your Choice:\t");
        scanf("%d",&choice);
        
        switch(choice)
		{
			case 1:   	//SEARCH
						printf("Enter Element to be search:\t");
						scanf("%d", &n);
						search(root, n);
						break;
						
			case 2:  	//INORDER
						printf("\nInorder traversal is:\t");
        				inorder(root);
						break;
						
			case 3 :	//EXIT
						printf("\t\t>>BYE<<");
						break;				
						
			default: printf("\t>>ENTER RIGHT CHOICE<<");		
           
		}	
	}while(choice!=3);
}										
