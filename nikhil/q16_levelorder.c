#include<stdio.h>
#include<stdlib.h>
#include "q16_levelorder.h"  

void main()
{
    NODE *root=NULL;
    printf("\t>>First Create BST<<\n");
    root = createbst(root);  		
    
	display(root);
    
	printf("\n\n\t>>Level order traversal<<\t");
    levelorder(root);
}
