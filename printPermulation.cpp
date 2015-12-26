#include <iostream>
#include <algorithm>
#include <vector>
 
using std::cout;
using std::endl; 

int main(){
	std::vector<int> list(10); 
	int i = 0; 
	for (auto &p : list)  {    p = i;  ++i;  }    // generate sequence with 0 - 9; 
	// sort( list.begin(), list.end(), [](int a, int b) { return a < b; } ); 
	do {
		for (auto p : list) cout << p << " "; 
			cout << endl; 
	} while (next_permutation(list.begin(), list.begin()+3)); 
}