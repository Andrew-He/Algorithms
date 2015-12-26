#include <algorithm>
#include <iostream>


using std::cout; 
using std::string; 

class CStudent{
	private:
		string sName; 
		int nAge; 
	public:
		bool good() { return true; };
		void setName(const string & name ){  sName = name; }
};

class CBachedolr : public CStudent {
private:
	int nDepartment; 
public:
	bool good() { std::cout << "3 is good";  return true; }
	bool CanGotoGraduateSchool() {
		return true; 
	}
};

int main(){
	CStudent s; 
	CBachedolr b; 

	cout << "size is " << sizeof(s) << " " << sizeof(b) << std::endl; 


}