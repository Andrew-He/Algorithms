#include <stack>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std; 
// implement with two stack 
struct Node {
	int val; 
	struct Node *next; 
};


int main(){
	int size = 10; 
	int **arr = (int**)malloc(sizeof(int*) * size); 
	for(int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int)*size);  
		 
	}

	arr[0][0] = 20; 
	arr[9][9] = 50; 
 

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t"; 
		}
		cout << endl; 
	}
	for(int i = 0; i < size; i++)
		free(arr[i]);  
	free(arr); 

	return 0; 
}