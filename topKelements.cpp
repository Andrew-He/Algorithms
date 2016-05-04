#include <vector>
#include <queue>  // std::priority_queue
#include <utility>  // pair 
#include <unordered_map>
#include <iostream>
using namespace std; 

class counter {
	public:
	    struct compare {
	        bool operator () (const pair<int, int> lhs, const pair<int, int> rhs)
	        {
	            return lhs.second < rhs.second; 
	        }
	    }; 
	    vector<int> topKFrequent(vector<int>& nums, int k) {
	        unordered_map<int, int> map; 
	     
	        priority_queue<pair<int,int>, vector<pair<int, int>>, compare > q; 
	        vector<int> res; 
	        for(int n : nums) map[n]++; 

	        for(auto entry : map )
	            q.push(pair<int, int>(entry.first, entry.second)); 
	        
	        for( int i = 0; i < k && !q.empty(); i++ )  {
	            res.push_back( q.top().first); 
	            q.pop(); 
	        }
	        return res; 
	    }
};

int main(){
	counter count; 
	vector<int> v = { 1, 2, 3, 4, 1, 2, 2}; 
	v = move(count.topKFrequent(v, 3)); 
	for(int n : v) cout << n << " " ; 
		// print 2 1 3 correct 
}

