#include <iostream>
#include <vector>

using namespace std; 

void partition(int n, vector<int>& v, int level){
	int first; 

	if (n < 1) return;
	v[level] = n; 
	for(int i = 0; i <= level; i++) {
		cout << v[i] << " "; 
	cout << endl;  
	}
	first = (level == 0)  ? 1 : v[level - 1]; 

	for(int i = first; i < n / 2; i++){
		v[level- 1] = i; 
		partition(n-i, v, level+1); 
	}
}

 