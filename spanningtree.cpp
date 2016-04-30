#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std; 




/* simple bfs search to test reachability between any two nodes in the graph */ 
// also can use BFS to detect loop in graph, when neighour of a node is already visited
bool isConnected(int dim, int graph[dim][dim], int src, int dest){
	unordered_set<int> visited; 
	queue<int> q; 
	visited.insert(src); 
	q.push(src);  // the index for src 

	while (q.empty()) {

		int size = q.size();  // get neighbourhood nodes 
		for(int i = 0; i < size; i++){

			int row = q.front(); 
			for(int j = 0; j < dim; j++) {
				// node j in the list
				if ( graph[i][j] > 0 && visited.find(j) != visited.end() ) { 
					q.push(j);
					visited.insert(j); 
				} 
				if ( graph[i][j] > 0 && j == dest) return true; 
			}

		}
	}
	return false;   // iterates to all neighour nodes NOT reachable
}





int main(){
	 
   /* Let us create the following graph   (take usage of geeksforgeeks matrix sample )
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},   // undirected graph is symmetric around the diagonal
                     };


}