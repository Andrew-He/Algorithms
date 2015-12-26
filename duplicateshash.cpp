#include <iostream>
#include <unordered_set>  // insert, lookup is O(1) than map 
#include <vector>
#include <numeric>
#include <random> 
#include <functional>
using namespace std; 

template<typename ForwardIterator>
ForwardIterator unordered_uniques(ForwardIterator first, ForwardIterator last)
{
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
    std::unordered_set<value_type> unique;
    return std::remove_if(first, last, [&unique](const value_type &element) mutable -> bool { return !unique.insert(element).second; }); // std::pair<iterator,bool> insert( const value_type& value );  // second is second element in Pair structure
}

std::unordered_set<value_type> unique; 
typename std::iterator_traits<T>::value_type value_type; 
return std::remove_if(first, last, [&unique](const value_type &element) mutable -> bool {return !unique.insert(element).second; };  


template<typename T>
T unordered_unique(T first, T last)
{ 
    std::unordered_set<value_type> unique;
    return std::remove_if(first, last, [&unique](const T &element) mutable -> bool { return !unique.insert(element).second; }); // std::pair<iterator,bool> insert( const value_type& value );  // second is second element in Pair structure
}
 

 /*
int main(){
	int size = 10; 
	vector<int> v(size); 
	std::iota(v.begin(), v.end(), 1);  // sequence generator
	shuffle(v.begin(), v.end(), std::mt19937( random_device{}() ) ); 

	auto func1 = [](int y) { 
		cout << y << " "; 
	}; 
	auto func2 = [](int y) {
		cout << y * y << " "; 
	}; 

 	double a = 10;  
 	cout << "a is in type of " << typeid(a).name() << endl;   // output 'i', double for 'd', float for 'f'
	cout << "func1 is : " << typeid(func1).name() << endl; 
	cout << "func2 is : " << typeid(func2).name() << endl;  

	cout << (void*)main << endl; 
	cout << "main is : " << typeid(main).name() << endl;

	 
	print_for_each(v, func1); 
	return 0; 
}
*/


int main(){
	vector<int> values = {1,2,3,4,5,8, 8, 3};
	auto p = unordered_unique(values.begin(), values.end()); 
	cout << "what is p "<< *p << endl;
	cout << "what is p++ " << *(++p) << endl;  
	cout << "what is p++ " << *(++p) << endl;  
	

	values.erase( p , values.end());     
	for_each( values.begin(), values.end(), [](int a)
		{ 
			cout << a << " "; 
		}
	); 

	//for(auto p : values)
	//	cout << p << " ";  cout << endl; 

	return 0; 
}
 