/* Satvik Dhandhania : Candidate */

/*
 		  A
	   /     \
	  B       C
	 /  \    /  \
	D    E  F    G
   / \     /      \
  H   I    J       K

*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
struct node
{
    char c;
    struct node *left,*right;
};
/* Add element to end of queue */
void addQueue(struct node** queue, int *end, struct node* n){
    queue[*end] = n;
    (*end)++;
}
/* Get first element from queue*/
struct node* removeQueue(struct node** queue, int *start, int *end){
	if((*start)<(*end))
    {
    	(*start)++;
    	return queue[(*start)-1];
	}
	else 
	{
		return NULL;
	}
}
/* Create Queue */
struct node** createQueue(int *start,int *end)
{
    //Assuming queue size to be a maximum of 100
   struct node **queue = (struct node **)malloc(sizeof(struct node*)*MAX_SIZE);
    *start = *end = 0;
    return queue;
}


/* Actual driving logic for functionality */
void printAllLevels(struct node* root)
{
    int start, end;
    struct node** queue = createQueue(&start,&end);
    struct  node* temp = root;
    int iteration_nodes = 1;
    int last_Val = iteration_nodes;
    int last_offset =0;
    int offset = 0;
    while(temp != NULL){
        printf("%c",temp->c);
        iteration_nodes --;
        
      
        if(temp->left != NULL)	{
            addQueue(queue,&end,temp->left);
        } else {
        	offset++;
        }
        if(temp->right != NULL)	{
            addQueue(queue,&end,temp->right);
        } else {
        	offset++;
        }
        /* If levels work has been completed */ 
        if((iteration_nodes) == 0){
        	printf("\n");
        	iteration_nodes = last_Val*2;
        	last_Val = iteration_nodes;x
        	last_offset = offset+ last_offset*2 ;
        	iteration_nodes = iteration_nodes - last_offset;
        	offset = 0;
        }
        temp = removeQueue(queue,&start,&end);   
    }
    free(queue);	
}
/* Create a new node for the tree. */
struct node* newnode(char c){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->c =c;
    node->left = NULL;
    node->right = NULL;
    return node;
}



int main()
{	
    struct node *root = newnode('A');
    root->left = newnode('B');
    root->right = newnode('C');
    root->left->left = newnode('D');
    root->left->right = newnode('E');
    root->right->left = newnode('F');
    root->right->right = newnode('G');

    root->left->left->left = newnode('H');
    root->left->left->right = newnode('I');
    root->right->left->left = newnode('J');
    root->right->right->right = newnode('K'); 

    root->left->left->left->right = newnode('S');
    root->left->left->left->right->left = newnode('T');
    

    printf("Level Traversal:\n");
    printAllLevels(root);
    
}

