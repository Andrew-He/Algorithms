#include <iostream>
#include <cassert>

// can used to create deque

using std::cout; 
using std::endl; 

struct Node{
	int val; 
	struct Node *next; 
	struct Node *prev; 
	Node(int val):val(val), next(nullptr), prev(nullptr){}
};

typedef struct Node Node; 

class LinkedList {
protected:
	Node *head;  
	Node *tail; 
public:
	LinkedList() { cout << "LinkedList is called\n"; head = nullptr; tail = nullptr; }
	~LinkedList(){ 
		int nodes_removed = 0; 
		while (head != nullptr){
			Node *cur = head; 
			head = head -> next; 
			delete cur;
			nodes_removed++;  
		}
		cout << nodes_removed << " nodes removed" << endl; 
	}
	// friend class deque;  
	void appendNodeToTail(int val) {
		Node *node = head; 
		if (node == nullptr){
			node = new Node(val); 
			head = tail = node;  
		} else {
			while (node -> next != nullptr) { node = node -> next; }
			node -> next = new Node(val); 
			tail = node; 
		}
	} 

	void traverse(){
		Node* cur = head; 
		while (cur != nullptr) { cout << cur -> val << " " << endl;  cur = cur -> next; } 
	}
};


int main(){

	
}







