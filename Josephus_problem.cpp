#include <iostream>
using std::cout; 

int josephus( int n, int k) {

	if (n == 1) 
		return 1; 
	else 
		return (josephus(n - 1, k) + k - 1 ) % n + 1;     // k - 1 person skipped
	/*
		After the first person (kth from begining) is killed, n - 1 person are left. 
		So we call josephus(n - 1, k) to get the positions with n - 1 person. 
		The position returned by josephus(n - 1, k) will consider the position starting from k%n + 1. we must make 
		adjustments to the position returned by josephus(n -1 , k); 

	*/
}

int jjj(n) {
	int i = 0x1


}

 
int main() {
	int n = 100; 
	int k = 2; 

	cout << josephus(6, 2);   
}