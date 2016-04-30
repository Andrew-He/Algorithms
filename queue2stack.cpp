class myQueue{
public:
	void push(int elem){
		int size = q.size();    // eat snake's tail 
		s.push(elem); 
		while (size--){
			q.push(q.front()); 
			q.pop(); 
		}
	}	
	int top(){
		return q.fromt(); 
	}
	int pop(){
		q.pop(); 
	}
	bool isEmpty(){
		return s.empty(); 
	}

private:
	queue<int> q; 
};