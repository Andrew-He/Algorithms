#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>

using std::cout;
using std::endl; 

/*
	reverse first k nodes in a linkedlist if k = 3 
	1 -> 2 -> 3 -> 4 -> 5 -> null 
	3 -> 2 -> 1 -> 4 -> 5 -> null
 */

int fibo(int n){

	//int result = 2^n - 1; 
//	cout << std::numeric_limits<decltype(n)>::max() << endl; 

	return 0; 
}

int main(){
	int n = 10000000000; 
	typedef int GodEye; 
	GodEye result = std::pow( 2, n ); 
	cout << result; 
	if ( result > std::numeric_limits<decltype(result)>::max())
		throw std::overflow_error("overflow in pow()");
	return 0;  
}


