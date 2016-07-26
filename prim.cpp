#include <iostream>
#include <unordered_set>

using namespace std; 

struct edge
{
	int _weight; 
	int _from, _to; 
	edge(int weight, int from, int to)
		: _weight( weight)
		, _from(from)
		, _to(to)
	{}
};


class Prim 
{
private:
	unordered_set<int> checked; 
	unordered_set<int> unchecked; 

public:	
	Prim() = delete; 
	explicit Prim( vector<edge> graph )
	{
		for_each( graph.begin(), graph.end(), 
				[&unchecked](const edge ed){
					unchecked.insert( ed._from ); 
					unordered.insert( ed._to ); 
				});   // init unchecked set 
		

	}  


};













