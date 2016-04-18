// typical backtrack problem 
// to generate all position sets....... power set
#include <vector>
#include <iostream>
using namespace std; 

class Solution{

public:

	vector<vector<int>> subsets(vector<int> S){
		vector<vector<int>> res; 
		if ( S.size() == 0 ) return res; 

		std::vector<int> list;
		std::sort(S.begin(), S.end(), [](int a, int b){ return a < b;});
		backtrack(res, list, S, 0); 
		return res; 
	}

	void backtrack(vector<vector<int>> &result, vector<int> &list, vector<int> S, int pos){
		result.push_back( list ); 
		for(int i = pos; i != S.size(); ++i) {
			if (i != pos && S[i] == S[i -1])
				continue; 
			list.push_back(S[pos]); 
				backtrack(result, list, S, i+1); 
			list.pop_back(); 

		}
	}
};




/* print 
 *		1 
 *		1 2 
 *		1 2 3 
 *		1
 *		1 3
 *		1
 */
int main(){
 
}