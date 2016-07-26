
template <typename T> class String 
{
public:
	String(); 
	explicit String(const T *); 
	String(const String &);
	String operator = (const String &); 
	T* operator[](int n) {  return ptr[n];  } 
	String &operator+=(T c); 

private:
	static const int short_max = 15; 
	int sz; 
	T* ptr; 
};


template <typename T>
String<T>::String() 
	: sz(0)
	, ptr{ch}
{
	ch[0] = {}; 
}

template <typename T>
String& String<T>::operator+=(T c)
{
	return *this; 
}