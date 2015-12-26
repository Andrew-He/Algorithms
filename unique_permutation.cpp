#include <iostream>
#include <random>
#include <algorithm>
#include <functional>

using namespace std; 

int getRandomInteger(){
	std::random_device rd; 
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dst(10, 100); 
	return dst( gen ); 
}

void generate_random_seq( vector<int> &arr ){

	iota(arr.begin(), arr.end(), getRandomInteger()); 
	shuffle(arr.begin(), arr.end(), std::mt19937( random_device{}() )); 

}
template <typename f>
void printAll(vector<int> arr, f&& func) {
	for_each( arr.begin(), arr.end(), func); 
}

int binarySearch(vector<int> v, int key, int start, int end){
	int mid; 
	if ( start > end ) {
		mid = start + (end - start) / 2; 
		if ( v[mid] == key )
			return mid; 
		else if ( key < v[mid] ) 
			return binarySearch( v, key, start, mid); 
		else 
			return binarySearch( v, key, mid, end); 
	}
	return -1; 
}

class node{
public:
	int data; 
	node* next; 
};

 


/*
int main() {
	auto print = [](int a){ cout << a << " "; };  

	vector<int> v(10); 
	generate_random_seq( v ); 

	printAll( v, print); 
	std::sort( v.begin(), v.end(), [](int a, int b)->bool{ return a < b;}); 
	//cout << "max number is " << max_element( v.begin(), v.end() ) << endl; 
	cout << "distance is " << std::distance( v.begin(), v.end() ) << endl; 
	cout << std::count_if( v.begin(), v.end(), [&v](int a)->int{ return a > 95; } ); 

	nth_element( v.begin(), v.begin() , v.end(), greater<int>()); 

	cout << "max is "<< v[0] << endl;  

	return 0; 
}*/

