#ifndef VECTOR_HPP
#define VECTOR_HPP
 

// icetea
template <typename Object>
class vector
{
	enum { _remained_capacity = 50 };
private:
	int theSize; 
	int theCapacity; 
	Object *objects; 

public:
	Object & operator[]( int index )
	{
		return objects[ index ];   
	}

	const Object & operator [](int index) const
	{
		return objects[ index ]; 
	}

	bool empty() const 
	{
		return size() == 0; 
	}

	int size() const
	{
		return theSize; 
	}

	int capacity() const 
	{
		return theCapacity; 
	}

	explicit vector(int _size = 0): theSize( _size), theCapacity ( _size + _remained_capacity ) { 
		objects = new Object[ theCapacity ]; 
	}
	vector( const vector & rhs ) : objects( nullptr ) { operator = (rhs);  } 
	~vector() { delete [] objects; }

	const vector & operator = (const vector & rhs)
	{
		if ( this != &rhs) 
		{
			delete [] objects; 
			theSize = rhs.size(); 
			theCapacity = rhs.theCapacity; 

			objects = new Object[ capacity() ]; 
			for( int i = 0; i < size(); i++ )
				objects[ i ] = rhs.objects[ i ];
		}
		return *this; 
	}

	void resize( int newSize )
	{
		if ( newSize > theCapacity )
			researve( newSize * 2 + 1 ); 
		theSize = newSize; 
	}

	void researve( int newCapacity ){
		if (newCapacity < theSize)
			return; 
		Object *oldArray = objects; 
		objects = new Object[ newCapacity ]; 
		for( int i = 0; i < theSize; i++ )
			objects[ i ] = oldArray[ i ]; 

		theCapacity = newCapacity; 
		delete [] oldArray; 
	}

	void push_back( const Object & x )
	{
		if ( theSize == theCapacity ) 
			researve( 2 * theCapacity + 1 ); 
		objects[ theSize++ ] = x; 
	}

	void pop_back() {
		if (theSize > 0) theSize--; 
	}

	const Object & back () const 
	{
		return objects[ theSize - 1]; 
	}

	typedef Object *iterator; 
	typedef const Object * const_iterator;  

	iterator begin( ) { return &objects[0]; }
	const_iterator begin( ) const {	return &objects[ 0 ]; }
	iterator end() { return &objects[ size() ]; }
};


	 

	 
#endif

