// Binary search tree should have create, insert, delete, traveral, lookup, empty, Min/Max, deep copy

#include <queue>
#include <iostream>
#include <vector>

using namespace std; 

#include <stdio.h>
#include <stdlib.h>

void Insert(struct node *root, int data); 
struct node
{
    int data; 
    struct node* left, *right; 
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node -> data = data; 
    node -> left = node -> right = NULL; // both children = null 
    return (node);
}

struct node* initTree() 
{ 
 //   vector<int> elements = {2, 7, 5, 6, 1, 11, 9, 4}; 

  //  for (vector<int>::iterator it = elements.begin(); it != elements.end(); it++ ) {
  //  	Insert(root, *it); 
   // }
    struct node *root    = newNode(2); 
    root -> left         = newNode(7); 
    root -> right        = newNode(5); 
    root -> left -> right= newNode(6); 
    root->left->right->left=newNode(1);
    root->left->right->right=newNode(11);
    root->right->right=newNode(9);
    root->right->right->left=newNode(4);
    return (root);  
}



void printInorder(struct node*root)
{
    if (root != NULL){ 
        printf("%d ", root -> data);
        printInorder(root -> left); 
        printInorder(root -> right); 
    }
}

bool SearchBST(struct node *node, int key){

	if (!node)
		return false;

	if (node -> data == key) 
		return true; 
	else if (node -> data < key)
		return SearchBST(node -> right, key); 
	else 
		return SearchBST(node -> left, key);
}

void Insert(struct node *root, int data) {
	if (!root)
	{
		root = (struct node*)malloc(sizeof(struct node)); 
		root -> left = nullptr; 
		root -> right = nullptr; 
		root -> data = data;  
	} else if (data < root -> data)
		Insert(root -> left, data); 
	else if (data > root -> data) 
		Insert(root -> right, data); 
	else; 
}

// the min val is located at the left most node of a Binary Tree
struct node* FindMin(struct node *node) {
	if (node == nullptr)
		return nullptr; 
	else if (node -> left == nullptr)
		return node; 
	else 
		return FindMin(node -> left); 
}

void MakeEmpty(struct node *root){
	if (root) 
	{
		MakeEmpty(root->left);
		MakeEmpty(root->right); 
		delete root; 
	}
	root = nullptr; 
}

void LevelOrderPrint(struct node *root){
	queue<struct node *> Q; 
	Q.push(root); 

	while (!Q.empty())
	{
		struct node *node = Q.front(); 
		cout << node -> data << " "; 

		if (node -> left) 
			Q.push(node->left); 
		if (node -> right)
			Q.push(node ->right); 
		Q.pop(); 
	}
	cout << endl; 
}

int max_depth(struct node* root) ; 
bool isBalancedBST(struct node* root){
	return max_depth(root); 
}

int max_depth(struct node* root) {
	if (root == nullptr) return false; 

	int left = max_depth(root->left);
	int right = max_depth(root->right);
	if (left == -1 || right == -1 || std::abs( left - right) > 1 )
		return false; 
	return max( max_depth(root->left) , max_depth(root->right) );
}

int main(){
	struct node *node = initTree(); 
	printInorder(node);  
	cout << endl; 
	cout << "the smallest element is " << FindMin(node)->data << endl; 
	
	isBalancedBST(node)?cout << "this bst is balanced":cout<<"not balanced"; 
	cout << endl; 
	//printInorder(node); 
	//cout << SearchBST(node, 7); 
	//LevelOrderPrint(node);
	
	MakeEmpty(node); 
	return 0; 
}

