/*
 * Author: Satvik Dhanhdhania Date: 04/03/2017
 * NetApp Telephonic Round
 * Update Binary Tree with the number of nodes that are present below it. 
 */

/*
 * Sample tree
 * 			1
 * 		   /  \
 *		  2    3
 *	     / \  / \
 *		4   5 6	 7
 *	     \		  \
 * 		  8		   9
 *
 */

/* Include Headers */
#include<stdio.h>
#include<stdlib.h>

struct Node 
{	
	int value;
	int num_children;
	struct Node* left;
	struct Node* right; 
};


/* new node logic */
struct Node* newNode(int val)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	if(node == NULL)
	{
		printf("\n Could not allocate node in heap !!");
		return NULL;
	} 
	node->value = val;
	/* Default assignment to check for incomplete traversal and unassigned nodes */
	node->num_children = -1;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* Updates the nodes with the number of children it has 
 * Time Complexity : O(n) since it traverses all the nodes
 */
void postOrderUpdateChildren(struct Node *node)
{
    if(node->left == NULL  && node->right == NULL)
    {
        node->num_children = 0;
        return;
    }
    /* Move to the left child if it exists */
    if( node->left != NULL) 
    {  
    	postOrderUpdateChildren(node->left);
    }
    /* Move to the right child if it exists */
    if(node->right != NULL) 
    {  
    	postOrderUpdateChildren(node->right);
    }
    /* Update the num_children for nodes based on children nodes it has. */
    // Both children are there
    if(node->left!=NULL && node->right!= NULL)
    {
        node->num_children = node->left->num_children + node->right->num_children + 2;
       
    }
    // Only right child exists
    if((node->left==NULL) && (node->right!= NULL))
    {
        node->num_children = node->right->num_children + 1;
       
    }
    // Only left child exists
    if((node->left!= NULL) && (node->right==NULL))
    {
        node->num_children = node->left->num_children + 1;
    }

    return;    
}
/* Given a binary tree, print its nodes in postOrder*/
void printPostOrder(struct Node* node)
{
     if (node == NULL)
          return;
     printPostOrder(node->left);
 	 printPostOrder(node->right);
     printf("%d -> %d\n", node->value, node->num_children);  

    
}

int main()
{
	/* Driver program to test above functions*/
     struct Node *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 
     root->right->left = newNode(6);
     root->right->right = newNode(7);
     root->left->left->right = newNode(8); 
     root->right->right->right = newNode(9);

     postOrderUpdateChildren(root);
     printf("Postorder traversal of binary tree is \nnode_value -> num_children\n");
 	 printPostOrder(root);

     return 0;
}
