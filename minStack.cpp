
// use 2 stacks 
class MinStack{
	stack<int> s; 
	stack<int> min;  
public:
	void push(int val){
		if ( min.empty() || val < min.top())
			min.push(val);
		s.push(val); 
	}
	void pop(int val){
		if (s.empty()) return; 
		if (s.top() == min.top())
			min.pop(); 
		s.pop(); 
	}
	int top(){
		return s.top(); 
	}
	int getMin(){
		return min.top(); 
	}
};

// use 1 stack 
class MinStack2{
	stack<int> s; 
	int min; 

public:
	void push(int val){
		if (min.empty() || val < min)
			min = val; 
		s.push(val);
	}
	void pop(){
		if (s.empty()) return; 
		if (s.top() == min) 
			min = std::numerical_limits<int>::min();  
		s.pop(); 
	}
	int top(){
		return s.top(); 
	}
	int getMin(){
		return min; 
	}

}