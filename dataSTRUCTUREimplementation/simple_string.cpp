#include <string.h>
#include <utility>  /* std::swap */
#include <iostream>

class String 
{
private:
	char * data_; 

public:
	String()
		: data_ (new char[1])
	{
		*data_ = '\0';   // for strcpy... CString 
	}

	String(const char *str)
		: data_(new char[strlen(str) + 1])  // padding '\0'
	{
		strcpy( data_, str); 
	}

	/* move constructor */
	String(String&& rhs) noexcept 
		: data_(rhs.data_)
	{
		rhs.data_ = nullptr; 
	}

	String(const String& rhs)
		: data_(new char[rhs.size() + 1])	
	{
		strcpy(data_, rhs.c_str());
	}

	~String() noexcept
	{
		delete[] data_; 
	}

	/* copy constructor */
	String & operator = (String rhs)   // copy and swap technique, so pass by value not reference
	{
		swap(rhs);
		return *this; 
	}

	size_t size() const 
	{
		return strlen(data_); 
	}
	const char* c_str() const 
	{
		return data_; 
	}
	void swap(String & rhs)
	{
		std::swap(data_, rhs.data_); 
	}

	 
};

 








int main()
{
	String s("god");
	std::cout << s; 
}


