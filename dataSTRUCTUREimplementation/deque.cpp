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
	virtual ~LinkedList(){ 
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
	// must be implemented in derived deque implementation at this example. 
	virtual void push_front(int ) = 0; 
	virtual void push_back(int )= 0; 
	virtual void pop_back() = 0; 
	virtual void pop_front() = 0;  

	void traverse(){
		Node* cur = head; 
		while (cur != nullptr) { cout << cur -> val << " " << endl;  cur = cur -> next; } 
	}
};


class deque : public LinkedList{
	public:
		int size; 
		deque(){ size = 0; cout << "deque is called\n"; }  
		~deque() { }

		int getLength(){
			int len = 0; 
			Node* copy = head; 
			while (copy != nullptr) {
				len++; 
				copy = copy -> next; 
			}
			cout << "len is " << len << endl;
			return len; 
		}

		void push_front(int val){
			if (head != nullptr){
				head -> prev = new Node(val); 
				head -> prev -> next = head; 
				head = head -> prev; 
			} else {
				tail = head = new Node(val); 
			}
		}
		void push_back(int val) {
			if (tail != nullptr){
				tail -> next = new Node(val); 
				tail -> next -> prev = tail; 
				tail = tail -> next; 
			}
		}
		void pop_back(){
			if (tail != nullptr) 
			{	
				if (tail -> prev != nullptr) {
					tail = tail -> prev; 
					delete tail -> next; 
					tail -> next = nullptr; 
				} 
				delete tail; 
				head = tail = nullptr; 
			}
			cout << "\n nothing to pop back\n"; 
		}
		void pop_front() {
			if (head != nullptr){
				if (head -> next != nullptr){
					head = head -> next;  
					delete head -> prev;  
					head -> prev = nullptr; 
				} else {
					delete head; 
					head = tail = nullptr; 
				}
			}
			cout << "\n nothing to pop front\n";
		}
};

int main(){
	deque dq;   
	dq.push_front(20); 
	dq.push_front(30); 
	dq.push_front(40); 
	dq.push_back(50); 
	//dq.pop_back(); 	 

	dq.traverse(); 
	return 0; 
}



