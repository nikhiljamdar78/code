//MAIN FILE
#include<stdio.h>
#include<stdlib.h>
#include "q18_csp.h"

NODE * create(NODE *root);
void postorder(NODE * root);
int sumEven(NODE *node1);

void main()
{
	NODE *root=NULL;
	int n, esum,choice;
	
	printf("\t\t\t>>First Create BST<<\n");
        		
    root = create(root);
    
    do
	{
		printf("\n\n1.Sum of Even Numbers");
		printf("\n2.Preoder");
		printf("\n Enter your Choice:\t");
        scanf("%d",&choice);
        
        switch(choice)
		{
			case 1:   	//SUM OF EVEN NUMBERS
						esum=sumEven(root);
						printf("\n Sum of even numbers is :\t%d",esum);
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
