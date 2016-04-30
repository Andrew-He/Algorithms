#include <string>

template <typename T>
class List
{
public:
	// override methods 
	virtual size_t size() = 0; 
	virtual ~List<T>() {};   
	virtual T& operator[](size_t i) = 0; 

	virtual void pop() = 0; 
	virtual void shift() = 0; 
	virtual void pop(T &into) = 0; 
	virtual void shift(T &into) = 0; 
	virtual void operator >> (T & into) {
		pop(into); 
	}
	virtual void operator << (T & into) {
		shift(into); 
	}

	virtual int index(const T& item) = 0; 
	virtual bool contains(const T& item) = 0; 

	virtual List<T>* sort() = 0; 
	void empty(){
		while (size() > 0) {
			pop(); 
		}
	}
}; 



