#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std; 


/* why cannot do this simple questiom during the interview, I am so stupid  */
void groupAnagrams(const vector<string> in) 
{
	unordered_map<string, vector<int>> map; 

	for(int id = 0; id < in.size(); id++)
	{
		string str = in[id]; 
		sort(str.begin(), str.end()); 
		map[str].push_back(id); 
	}
	for(unordered_map<string, vector<int>>::iterator it = map.begin(); it != map.end(); it++ )
	{
		for( int i = 0; i < (it -> second).size(); i++ )
		{
			cout << in[ (it->second)[i] ] << " ,"; 
		}
		cout << endl; 
	}
}
 


int main()
{
	vector<string> in;  
	in.push_back("abc"); 
	in.push_back("cba"); 
	in.push_back("abd"); 

	groupAnagrams(in);


	return 0; 
}



