#include <iostream>

using namespace std; 

void move(char, char); 
void hannoi(int n, char x, char y, char z) {
	if ( n <= 1) 
		move(x,z);
	else {  
		hannoi( n - 1, x , z, y); 
		move(x,z); 
		hannoi( n - 1, y,  x, z); 
	}
}


void move(char x, char y) {
	cout << "move from " << x << " to " << y << endl; 
}

int main() {
	// our goal is to move all disks on pillar A to pillar C  
	hannoi(2, 'A', 'B', 'C'); 
	return 0; 
}