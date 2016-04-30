#include "generic_list.h"

using std::function; 

template <typename T>
class LinkedList : public List<T>
{
public:
	typedef T value_type; 
	size_t size() override; 

	LinkedList<T>(); 
	LinkedList<T>(T item); 
	LinkedList<T>(const LinkedList<T> & copy); 
	~LinkedList<T>() override; 

	T& operator [](size_t i) override; 

	LinkedList<T>* push(T item) override; 
	LinkedList<T>* unshift(T item) override; 

	void pop() override; 
	void shift() override; 
	void pop(T & into) override; 
	void shift(T & into) override; 
	using List<T>::operator >>; 
	using List<T>::operator <<; 

	int index(const T& item) override; 
	bool contains(const T& item) override; 

protected:
	size_t length = 0; 
	struct Node {
		friend class LinkedList<T>; 
		T item; 
		Node* next = nullptr; 
		Node() {};
		Node(T item) : item(item) {};
		Node(Node * next) : next(next){};
		Node(T item, Node* next) : item(item), next(next) {};
		Node(Node* next, T item) : item(item), next(next) {};
		void operator = (T item){
			this -> item = item; 
		}; 
	};
	Node * head = nullptr; 
	Node * tail = nullptr; 
	Node * node_at(long int i); 

public:

	struct iterator {
		friend class LinkedList<T>; 
		friend class Node; 

		T& operator ->(){
			return operator *(); 
		}
		T& operator *() {
			return cursor -> item; 
		}
		bool operator==(iterator& right){
			if (index == end || right.index == end) {
				return right.index == index; 
			}
			return operator *() == *right; 
		}
		bool operator != (iterator & right){
			return !operator == (right); 
		}
		iterator& operator++(){
			if (cursor -> next != nullptr) {
				cursor = cursor -> next; 
				index++; 
			} else {
				index = end; 
			}
			return *this; 
		}
		iterator& operator --(){
			if (index == end) {
				cursor = _list.tail; 
			} else {
				if (index > 0) {
					index--; 
					cursor = _list.node_at(index);
				} else {
					index = end; 
				}
			}
			return *this; 
		}
	protected: 
		iterator(Node & node, size_t from_index, LinkedList<T> &list) : index(from_index), _list(list){
			cursor = &node; 
		}
		iterator(LinkedList<T>& list) : _list(list){
			index = end; 
		}
		const long int end = -1; 
		Node* cursor; 
		long int index; 
		LinkedList<T>& _list; 
	};

	template class LinkedList<std::string>;
	template class LinkedList<int>; 
	template class LinkedList<double>; 
};




