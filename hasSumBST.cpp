#include <iostream>

using std::cout; 
using std::endl; 

// test if a bst has a target sum 
using namespace std; 

#include <stdio.h>
#include <limits.h>

struct node
{
	int data; 
	struct node* left; 
	struct node* right; 
};
bool hasPathSum( struct node* node, int sum) 
{
	if (node == nullptr)
	{
		return (sum = 0); 
	} else {
		bool ans = 0; 
		int subSum = sum - node -> data; 

		if ( subSum == 0 && node -> left == nullptr  && node -> right == nullptr)
			return 1; 
		if (node -> left) 
			ans = ans || hasPathSum( node -> left, subSum); 
		if (node -> right)
			ans = ans || hasPathSum( node -> right, subSum);
		return ans; 
	}
} 

struct node* newnode( int data) 
{
	struct node * node = (struct node*) malloc(sizeof(struct node));

	node -> data = data; 
	node -> left = nullptr; 
	node -> right = nullptr; 
	return node; 
}

int main() {
	int sum = 21; 

	struct node * root = newnode(10); 
	root -> left = newnode(8); 
	root -> right = newnode(2); 
	root -> left -> left = newnode(3); 
	root -> left -> right = newnode(3); 	
	root -> right -> left = newnode(2); 

	if (hasPathSum(root, sum))
		std::cout << "yes" << std::endl; 
	else 
		std::cout << "no" << std::endl; 

	return 0; 
}

struct queueEntry
{	
	int v; 
	int dist; 
};

int getMinDiceThrows()
{
	bool *visited = new bool[N]; 
	for (int i = 0; i < N; i++)
		visited[i] = false; 

	std::queue<queueEntry> q; 

	visited[0] = true; 
	queueEntry s = {0, 0}; 
	q.push(s); 

	queueEntry qe; 
	while (!q.empty()){
		qe = q.front(); 
		int v = qe.v; 
		if ( v == N -1 )
			break; 

		q.pop(); 
		for( int j = v+1; i <= (v+6) && j < N; ++j) {  // get front entries
			if (!visited[j]) 				// if not visited  put in queue 
			{				
				queueEntry a;				 
				a.dist = (qe.dist + 1);             
				visited[j] = true; 

				if (move[j] != -1 )
					a.v = move[j]; 
					visited[j ]= true; 
				else 
					a.v = j; 

				q.push(a);
			}

		}

	}
	return qe.dist; 
}






 one algorithm question and one oo design question. 

 Finding the length of the longest substring containing unique characters 

 Given a word, convert it into the equivalent Phonespell numbers, and also vice versa, generating a list of possible words from a string of numbers.

 Given a tree (of any kind), and two nodes in the tree, find the shortest path between the two nodes.

 Divide a number using only addition and subtraction.  

given a table of users and posts, write a data structure and method that would give us the top favourited posts (no database).

construct the most efficient data structures so that the retrieval of information should be relatively fast

Snake ladder problem.

find all the anagrams of a given English word as fast as possible 

get the k smallest number of an array of n elements

	- nth element 
	- Max/Min Heap to query to Heap.top();  sort 


 


