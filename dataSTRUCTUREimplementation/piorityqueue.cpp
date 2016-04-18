
// implment use binary heap using array 
// has to get min element in O(1) : heap order property 
#include <vector>

using namespace std; 

template <typename Comparable>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100); 
	explicit BinaryHeap(const vector<Comparable> & items)
		: array( items.size() + 10), currentSize( items.size() )
		{
			for(int i = 0; i < items.size(); i++ )
				array[ i + 1 ] = items[ i ]; 
			buildHeap();  
		} 

	bool isEmpty() const; 
	const Comparable & findMin() const; 

	void insert(const Comparable & x) {
		if (currentSize == array.size() - 1)
			array.resize( array.size() * 2); 

		int hole = ++currentSize; 
		for( ; hole > 1 && x < array[ hole / 2]; hole /= 2) 
			array[hole] = array[hole / 2]; 
		array[ hole ] = x; 

	}; 
	void deleteMin(){
		if (isEmpty())
			throw UnderflowException(); 
		array[ 1] = array[ currentSize-- ]; 
		percolateDown(1); 

	}
	void deleteMin( Comparable & minItem ){
		if (isEmpty())
			throw UnderflowException(); 
		minItem = array[1]; 
		array[1] = array[currentSize--];  
		percolateDown(1); 
	} 
	void makeEmpty(); 

private:
	int currentSize; 
	vector<Comparable> array; 

	void buildHeap() {
		for( int i = currentSize / 2; i > 0; i-- )
			percolateDown(i); 
	}
	void percolateDown(int hole){
		int child; 
		Comparable tmp = array[ hole ]; 
		for( ; hold * 2 <= currentSize; hole = child) 
		{
			child = hole * 2; 
			if (child != currentSize && array[ child + 1] < array[ child ])
				child++; 
			if ( array[ child ] < tmp ) 
				array[ hole ] = array[ child ]; 
			else
				break;  
		}
		array[ hole ] = tmp; 
	} 

};



