#include <iostream>
#include <vector>

using namespace std; 
int main(){

	vector<int> v(100, 0); 
	fill(v.begin(), v.end(), [](int &a){ static int n = 1; a = n, ++n; });

	for_each(v.begin(), v.end(), [](int a ){ cout << a << " "; });


	return 0; 
}