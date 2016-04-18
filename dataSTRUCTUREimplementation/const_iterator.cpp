struct Node {
	int data; 
	Node* prev; 
	Node* next; 
	Node(const Object & d = Object(), Node *p = nullptr, Node *n = nullptr)
		: data(d), prev(p), next(n) {}
};

class const_iterator
{
	Node *current; 
	Object & retrieve() const { return current -> data; }
	const_iterator( Node *p) : current(p) {}
	friend class List<Object>
public:
	const_iterator(): current( nullptr); 
	const Object & operator*() const { return retrieve();}
	const_iterator & operator++ (){
		current = current -> next; 
		return *this; 
	}
	const_iterator operator++ () 
	{
		const_iterator old = *this; 
		++(*this);
		return old; 		
	}
	bool operator == (const const_iterator &rhs) const 
	{
		return current == rhs.current; 
	}
	bool operator != (const const_iterator & rhs) const 
	{
		return !( *this = rhs); 
	}

}