#include <stack>

// queue:  1 2 

front 
// in:    1  2 
// out:   get front  pop in push out get bottom of in

pop:
// in :   1  2 
// out:   2  1



class Queue{
	stack<int> in; 
	stack<int> out; 

public:
	void move()
	{
		while (!in.empty()){
			in x = in.top();
			in.pop(); 
			out.push(x);
		}
	}

	void push(int x)
	{
		in.push(x); 
	}
	void pop() // remove first element in front 
	{ 
		if (out.empty())
			move(); 
		if (!out.empty())
			out.pop(); 	
	}
	int front() // get front element
	{
		if (out.empty()) 
			move(); 
		if (!out.empty()) 
			return out.top(); 
	}
	void empty()  // return if queue is empty
	{
		return in.empty && out.empty; 
	}
};

int main(){
	Queue q; 

	q.push(10); 
	q.push(20); 
	cout << q.front(); 

	return 0; 
}