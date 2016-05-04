#include <iostream>
#include <limits>		// std::numerica_limits
#include <algorithm>  // std::fill 
#include <cassert>
#include <iterator>

using namespace std; 


bool isAnagram(string s1, string s2)
{
	if (s1.length() != s2.length()) return false; 
	// deal with upper cases and lower casees and duplicate characters 
	int ch_limit = numeric_limits<unsigned char>::max() + 1; 
	char ch_map[ ch_limit ]; 
	

	for(int i = 0; i < s1.length(); i++)
		ch_map[ s1[i] - '\0']++; 
	for(int i = 0; i < s2.length(); i++)
		if (ch_map[s2[i] - '\0'] < 0) return false; 
		else ch_map[s2[i] - '\0']--; 

	return true; 
}

bool isAnagramSTL(string s1, string s2)
{
	sort(s1.begin(), s1.end()); 
	sort(s2.begin(), s2.end());
	return s1.compare(s2); 
}




void testcase(){
	assert( isAnagram("abc", "cba") == true ); 
	assert( isAnagram("abc", "cbad") == false );
	assert( isAnagram("abc", "cbc") == true );  
	assert( isAnagram("abc", "cba") == true ); 
}

int main(){
	testcase();

	cout << "success!" << endl;
 	
 	return 0; 
}





