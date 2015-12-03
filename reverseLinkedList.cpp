#include <iostream>

using namespace std; 

// number = min + ( rand() % (int)( max - min + 1)); 


class node {
public:
	int v; 
	node * next; 

	node(int _v): v(_v) {} 
};

node * getLinkedList(int size) {

	node *head = nullptr; 

	for (int i = 0; i < size; i++ )
	{
		node *tmp; 
		tmp = new node(i); 
		tmp -> next = head; 
		head = tmp;   
	}
	return head; 
}

node* reverse(node * head) {
	node* newHead = nullptr; 
	
	while (head) {
		node* next = head -> next; 
		head -> next = newHead; 
		newHead = head; 
		head = next; 
	}
	return newHead; 
}


void printList(const node *head) {

	while ( head -> next) {
		cout << head -> v << endl; 
		head = head -> next; 
	}
}

int main() {

	printList(getLinkedList(10)); 
	cout << "\n After Reverse Applied\n"; 
	printList(reverse(getLinkedList(10))); 

	return 0; 
}