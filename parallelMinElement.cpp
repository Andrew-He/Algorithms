#include <iostream>
#include <cstdlib>
#include <thread>

// utilize multicores 
using namespace std; 

class A {
public:
	A(int _a, int _b):a(_a), b(_b){} 
 
	static void showA() {
		cout << "a is " << << endl; 
	}

private:
	int a; 
	int b; 
};


int main(){
	A a(1,2);  
	A::showA();  
	return 0; 
}
