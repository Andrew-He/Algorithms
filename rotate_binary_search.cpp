#include <iostream>
#include <vector>

using namespace std; 
// search an element in a rotated sorted array, the interesting property is L + R, either one will be sorted
// time complexity is same as bst: divide and conquey O(log N)   
// terminated search if left == right or crossover 

// iterative approach  
template <class T>
int rotate_binary_search(const vector <T> arr, T key, int N) {
	int L = 0; 
	int R = N - 1; 

	while (L <= R) {

		int M = L + ((R - L) / 2);
		if ( arr[M] == key) return M; 

		if ( arr[L] <= arr[M] ) {
			if ( arr[L] <= key && key < arr[M] ) 
				R = M - 1; 
			else
				L = M + 1;  
		} else {
			if (arr[M] < key && key <= arr[R] )
				L = M + 1; 
			else 
				R = M - 1; 
		}

	}
	return - 1; 
}

// recursive approach to binary search 
template <class T>
int recursion_rotate_bs(const vector<T> arr, T key, int start, int end) 
{
	if (start <= end){
		int m =  (start + end) / 2; 

		if ( key == arr[m] ) 
			return m; 
		else {

			if (arr[start] <= arr[m]) {
			
				if ( key < arr[m] && key >= arr[start] )
					return recursion_rotate_bs(arr, key, start, m -1 );   // search the first half sequence 
				else 
					return recursion_rotate_bs(arr, key, m + 1, end ); 
			} else {
				if ( key > arr[m] && key < arr[m] ) 
					return recursion_rotate_bs( arr, key, m + 1, end); 
				else 
					return recursion_rotate_bs( arr, key, start, m - 1); 
			}		
		}

	}
	return -1; 
}



int main(){

	auto arr = {4, 5, 6, 7, 0, 1, 2};  
//	decltype(arr)::iterator it = arr.begin(), ite = arr.end(); 

	cout << "found at array position " << rotate_binary_search<int>(arr, 5, arr.size()) << endl;    //return position 1
	cout << "found at array position " << recursion_rotate_bs<int>(arr, 5, 0, arr.size()) << endl;    //return position 1


	return 0; 
}