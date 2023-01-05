//MAIN FILE
#include<stdio.h>
#include<stdlib.h>
#include "q6_csp.h"

NODE * create(NODE *root);
void preorder(NODE * root);
int sumOdd(NODE *node);

void main()
{
	NODE *root=NULL;
	int n, num, osum,choice;
	
	printf("\t\t\t>>First Create BST<<\n");
        		
    root = create(root);
    
    do
	{
		printf("\n\n1.Sum of Odd Numbers");
		printf("\n2.Preoder");
		printf("\n Enter your Choice:\t");
        scanf("%d",&choice);
        
        switch(choice)
		{
			case 1:   	//SUM OF ODD NUMBERS
						osum=sumOdd(root);
						printf("\n Sum of odd numbers is :\t%d",osum);
						break;
						
			case 2:  	//PREORDER
						printf("\nPerorder traversal is:\t"); 
       					preorder(root);
						break;
						
			case 3 :	//EXIT
						printf("\t\t>>BYE<<");
						break;				
						
			default: printf("\t>>ENTER RIGHT CHOICE<<");		
           
		}	
	}while(choice!=3);
}										
