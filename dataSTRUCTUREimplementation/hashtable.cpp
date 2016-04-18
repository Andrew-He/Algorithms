/*
 *	linear probing hashtable and separate chaining 
 *		(open address and closed address)
 *	
 */
 #include <vector>

using std::vector; 
 template <typename obj>
 class HashTable{
 	vector<vector<obj> > theLists; 
 	int currentSize; 
 	void rehash(); 
 	int myHash(const obj & x) const 
 	{
 		int hashVal = hash(x); 

 		hashVal = hashVal % theLists.size(); 
 		if (hashVal < 0) 
 			hashVal = hashVal + theLists.size(); 
 		return hashVal; 
 	} 

public:
	explicit HashTable(int size = 101); 
	bool contains( const obj & x) const; 

	void makeEmpty(); 
	bool insert( const obj & x); 
	void remove( const obj & x); 
 };

template <typename obj>
 bool HashTable<obj>::insert(const obj & x){
 	itn currentPos = findPos(x);
 
 }

int main(){


}