#include <iostream>


typedef unsigned int size_t; 


class string{
public:
	string(const char *str = nullptr); 
	string(const string *str); 
	~string(); 

	string operator+(const string &str) const;  // do not modify member

	friend ostream & operator << (ostream &os){
		
	}



private:
	char *data; 
	size_t length; 
};