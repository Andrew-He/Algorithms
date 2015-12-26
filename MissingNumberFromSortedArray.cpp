#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random> 
#include <stdio.h>

using namespace std; 

int playwithstatic(){
	static int number = 1; 
	return number++; 
}


int bs(const int arr[], int key, int start, int end){
	int mid; 
	while (start < end) {
		mid = start + (end - start) / 2; 
		if ( key == arr[mid]) {
			return mid; 
		} else if ( key < arr[mid] ){
			end = mid; 
		} else {
			start = mid; 
		}
	}
	return -1; 
}

 

bool isPalindrome(string str) {
	if (str.length() <= 1) return true; 
	auto first = str.begin(); 
	auto last = str.end() - 1; 

	while (first < last)
	{
		cout << " first is " << *first << " last is " << *last << endl;  
		if ( *first != *last) {
			return false; 
		}
		++first; 
		--last; 
	} 
	return true; 
}

/*
int main(){
	int size = 7; 
	int arr[] = {1, 2, 3, 4, 7, 9, 12}; 
	for (int i = 0; i < size; ++i) {
		cout << "key is " << arr[i] << " pos is " << bs(arr, arr[i], 0, size) << endl; 
	}
	
	return 0; 
}
*/
bool isPalindromeSTL(string str){
	string str2 = str;  
	reverse( str.begin(), str.end());  
	return !str.compare(str2);    // return 0 if same strings
}

template <class TT>
void reverseString( TT &first, TT &last) {
	while (first != last && first != --last) {
		swap(first++, last);
	}	
}

template <class TT>
void swap(TT & a, TT & b){
	TT c(b); 
	b = a; 
	a = c;
} 


int main(){
	int size = 5; 
	vector<int> vc(size);
	iota(vc.begin(), vc.end(), 0);  // fill an increasing sequence starting from zero 
	shuffle(vc.begin(), vc.end(), std::mt19937(random_device{}()));   // shuffle sequence randomly with random_device seed to generate random number using mt19937 algorithm 
	
	std::sort(vc.begin(), vc.end(), []( int a , int b){ return a < b; }); 
	for (auto p : vc) cout << p << " "; 
		cout << endl; 

 	std::srand(std::time(0)); 
 	int randselect = rand() % size; 
 	int numberRemoved = vc[randselect]; 
 	vc[randselect] = 0; 
 	int result = 0; 
 	for (int i = 0; i < size; i++)
 	{
 		cout << i << "is " << result << endl; 
 		result ^= vc[i]; 
 	}
 	for (auto p : vc) cout << p << " "; 
		cout << endl; 

 	cout << "random select " << numberRemoved << " to remove\n";
 	cout << "the number missed is " << result << endl;  

 	cout << playwithstatic() << " " << playwithstatic() << " " << playwithstatic() << endl; 

 	cout << " is string goog " << " palindrome " << isPalindromeSTL(string("goog")); 

 	cout << " reverse string apple is " << endl;  
 	return 0; 
}



