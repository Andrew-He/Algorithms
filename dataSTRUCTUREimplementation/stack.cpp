// naiive implementation of stack out of fixed array 

#include <iostream>
#include <vector>


using std::cout;
using std::endl; 

class stack1{
private:
	int _top;
	int _stack[100];  
	int _size; 

public:
	stack1(){
		_top = 0; 
		_size = 0; 
		clear(); 
	}
	int top(){
		return _stack[_top]; 
	}
	void push(int elm) {
		_stack[++_top] = elm; 
		++_size; 
	}
	void pop(){
		if (_top) 
			_stack[_top--] = 0; 
		--_size; 
	}
	void clear(){
		for(int i = 0; i < _size; i++){
			_stack[i] = 0; 
		}
		_size = 0; 
	}
	int size(){
		return _size; 
	}
	bool empty(){
		return _size == 0; 
	}
	void print(){
		for(int i = _size; i > 0; i--)
			cout << _stack[i] << endl; 
	}
};

using namespace std; 

template <typename T>
struct Node{
	T val; 
	struct Node *next; 
	Node(T _val):val(_val), next(nullptr){} 
};

template <typename T>
class stack{
private:
	Node<T> *top; 
	int size; 
public:
	stack(){ top = nullptr; size = 0; }
	~stack(){
		while (top != nullptr){
			Node<T> *node = top;
			top = top -> next; 
			delete node;  
		}
	}
	stack(vector<int> v); 
	void traverse(); 
	void push(T val); 
	void pop();  
}; 

template <typename T>
stack<T>::stack(vector<int> v){
	for(int n : v){
		this -> push(n); 
	}
}

template <typename T>
void stack<T>::pop(){
	if (top != nullptr){
		Node<T> *node = top; 
		top = top -> next; 
		delete node; 
		--size; 
	} 
}

template <typename T>
void stack<T>::push(T val){
	if (top != nullptr) {
		Node<T>* node = new Node<T>(val); 
		node -> next = top; 
		top = node; 
	} else {
		top = new Node<T>(val); 
	}
	++size; 
}

template <typename T>
void stack<T>::traverse(){
	while (top != nullptr) {
		cout << top -> val << endl; 
		top = top -> next; 
	}
}

int main(){
	vector<int> v(10, 0); 
	for_each(v.begin(), v.end(), [](int &a){ static int n = 1; a = n; ++n;  }); 
	//stack s(v); 
	stack<int> s(v);
	s.traverse(); 
	return 0; 
}



// linked list implementation 
/*
int main() {
	stack s; 
	s.push(10); 
	s.push(20);
	s.push(30); 
	s.print(); 
	s.clear(); 
	s.print(); 
}
*/ 