#include <iostream>


using namespace std; 

// idea is to play on 10th digit every time in iteration.
// input: 123 
// output: 321 
int reverseNumber(int x) {
	int rst = 0; 
	while (x != 0) {   
		int rst_next = rst * 10 + x %10;   
		x = x / 10; 
		if ( rst_next / 10 != rst ){
			rst = 0; 
			break;
		}
		rst = rst_next; 
	}
	return rst; 
}


int main(){
	cout << reverseNumber(123); 

}