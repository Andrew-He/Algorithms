#include <iostream>
#include <cassert>
#include <memory>

// can used to create deque

using std::cout; 
using std::endl; 
using std::shared_ptr; 
using std::unique_ptr; 


struct Node{
	int val; 
	Node *next; 
	Node *prev; 
	Node(int val):val(val), next(nullptr), prev(nullptr){}
};

typedef struct Node Node; 

class LinkedList {
protected:
	Node *head;  
	Node *tail; 
	/* new added */ 
	int _num_nodes; 
public:
	LinkedList() { cout << "LinkedList is called\n"; head = nullptr; tail = nullptr; _num_nodes = 0; }    
	~LinkedList(){ 
		cout << "destructor for " << __PRETTY_FUNCTION__ << " at " << &(*this) << endl; 
		int nodes_removed = 0; 
		while (head != nullptr){
			Node *cur = head; 
			head = head -> next; 
			delete cur;
			nodes_removed++;  
		} 
		cout << nodes_removed << " nodes removed" << endl; 
	}
	/* wrong code 
	LinkedList(LinkedList && other)
			: head(nullptr)
			, tail(nullptr)
	{
		*this = std::move(other); 
	}
	*/ 
	
	LinkedList (const LinkedList &other) 
			:  _num_nodes( other._num_nodes)
	{ 
		delete this -> head; 
		delete this -> tail; 
		Node *cur = other.head; 

		while (cur != nullptr){
			this -> appendNodeToTail( cur -> val); 
			cur = cur -> next;  
		}
	}	 

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
	LinkedList l; 
	l.appendNodeToTail(10); 
	l.appendNodeToTail(20); 
	//l.traverse(); 
	//LinkedList ll(l); 
 
	ll.traverse(); 
	return 0; 

}







