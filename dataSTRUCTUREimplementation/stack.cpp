// naiive implementation of stack out of fixed array 

#include <iostream>
#include <vector>

using std::cout;
using std::endl; 

class stack{
private:
	int _top;
	int _stack[100];  
	int _size; 

public:
	stack(){
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