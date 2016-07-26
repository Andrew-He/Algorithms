/* Morris traversal O(1) space complexity, using no stack 
 * (in general, traversal bt using stack/queue, recursion is typical ... poster/in/pre, level)
 *   
 *   inorder: 
 *   	while ()
 *   		if cur node has no left leave
 *   			visit 
 *   			go to right node 
 *   		else 
 *   			find left child node's right node B, re-point B to cur node 
 *   			go to left child node 
 */ 

#include <iostream>


void inorder_morris (struct node *root)
{
	struct node *p = root, *t; 
	while ( p != NULL )
	{
		if ( p -> left == NULL ) 
		{	
			cout << p -> key; 
			p = p -> right; 
		} else 
		{
			t = p -> left; 
			while ( t -> right != NULL && t -> right != p )
				t = t -> right; 

			if ( t -> right == NULL )
			{
				t -> right = p; 
				p = p -> left; 
			} else 
			{
				cout << p -> key; 
				t -> right = NULL; 
				p = p -> right ;
			}
		}
	}
}