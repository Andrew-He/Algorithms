#include <iostream>
#include <vector>
#include <string>
#include <limits>
// string counts 

// true: "abcd" and "dcab"
// introduce extra array counts table
using namespace std;

int maxCharSize = std::numeric_limits<char>::max(); 

bool isAnagram(string str1, string str2)
{
	vector<int> list1(maxCharSize, 0);   // max char_length 
	vector<int> list2(maxCharSize, 0); 
	cout << "max char size is "<< maxCharSize << endl; 

	if (str1.length() != str2.length()) return false; 

	for (int i = 0; i < str1.length(); i++) {
		list1[static_cast<int>(str1[i])] += 1; 
		list2[static_cast<int>(str2[i])] += 1; 
	}
	for (int i = 0; i < maxCharSize; i++) {
		if (list1[i] != list2[i] ) return false; 
	}
	for(int i = 0; i < maxCharSize; i++) {
		if (list1[i] != 0 || list2[i] != 0) 
			cout << "at " << i << " " << list1[i] << " : " << list2[i] << endl; 
	}
	return true;
}



int main(){
	string str1("abce"); 
	string str2("aaaa"); 

	cout << isAnagram(str1, str2) << endl; 
	return 0; 
}