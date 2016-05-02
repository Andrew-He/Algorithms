
#ifndef GRAPH_H
#define GRAPH_H



#include <iostream>
#include <unordered_set>

namespace Graph 
{
	class Edge 
	{
		private:
			int weight; 
			int fromId, toId; 
		public:
			Edge(int theWeight, int new_fromId, int new_toId);
			int getWeight() const; 
			void setWeight(int theWeight);  
			
	};

}
#endif