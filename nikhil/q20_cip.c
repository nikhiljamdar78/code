//MAIN FILE
#include<stdio.h>
#include<stdlib.h>
#include "q20_cip.h"

NODE * create(NODE *root);
void postorder(NODE * root);
NODE * insert(NODE *root,int n);

void main()
{
	NODE *root=NULL;
	int n, esum,choice;
	
	printf("\t\t\t>>First Create BST<<\n");
        		
    root = create(root);
    
    do
	{
		printf("\n\n1.Insert");
		printf("\n2.Postoder");
		printf("\n Enter your Choice:\t");
        scanf("%d",&choice);
        
        switch(choice)
		{
			case 1:   //INSERT
						printf("\n\nEnter Element you want to insert:\t");
    					scanf("%d",&n);
						root = insert(root,n);
						break;
						
			case 2: 	//POSTORDER
						printf("\nPostorder traversal is:\t");
        				postorder(root);
						break;
						
			case 3 :	//EXIT
						printf("\t\t>>BYE<<");
						break;				
						
			default: printf("\t>>ENTER RIGHT CHOICE<<");		
           
		}	
	}while(choice!=3);
}										
