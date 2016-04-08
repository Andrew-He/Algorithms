#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>


typedef unsigned int uint; 

template <typename T>
class vector{
private:
	T *begin_; 
	T *end_; 
	T *capacity_; 
public:
	vector( vector && temp) : begin_( temp.begin), end_( temp.end ), capacity_( temp.capacity) 
	{
		temp.begin_    = nullptr; 
		temp.end_      = nullptr; 
		temp.capacity_ = nullptr; 
	}	
	~vector(); 

	void clear(); 


	void push_back(T t);   
	void pop_back(); 

	ostream& operator << (ostream &os); 

};




#endif

