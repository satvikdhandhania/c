/* Apple Maps Engineering Telephonic Interview Q2*/

/* http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number */
/*
 Find if there is a path from the root to the leaf node having a certain sum in the binary tree. 
*/
 #include<stdio.h>


 bool sumPathRootToLeaf(struct node* root, int sum){

 
 	if(root == NULL){
 		/* Depends on the scenario we want to predict and report this case */
 		return (sum == 0); 
 	}
 
 	bool res = false;
 	int interval_sum = sum - root->val; 

 	if((interval_sum == 0) && (root->left == NULL) && (root->right == NULL))
 		return true;

 	if(root->left != NULL)
 		res = res | sumPathRootToLeaf(root->left, interval_sum);
 	if(root->right != NULL)
 		res = res | sumPathRootToLeaf(root->right, interval_sum);
 
 	return res;
 }
