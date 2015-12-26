#include <iostream>
#include <algorithm> // std::make_heap, pop_heap, push_heap, sort_heap
#include <vector>
#include <functional>
#include <queue>

// build a max heap using c+11 feature 
// a heap includes create-heap, heapify, merge (preserve original structure0, meld (join two heaps: destroy original structure).  

// external function like finx_max, insert, delete-max, replace 
using namespace std; 
/*
int main(){

	int arr[] = {10, 20, 30, 40, 4, 13}; 
	
	vector<int> v(arr, arr+6); 
	make_heap(v.begin(), v.end());
	cout << "max heap is " << v.front() << endl;
	v.push_back(99);
	std::sort_heap( v.begin(), v.end()); 
	push_heap(v.begin(), v.end());

   std::cout << "final sorted range :";
 	
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
} */

struct Node {
	int key; 
	int value;
};
struct cmpLess
{
	bool operator () (const Node &a, const Node &b){
		return a.key < b.key; 
	}
};
struct cmpGreater
{
	bool operator () (const Node &a, const Node&b) {
		return a.key > b.key; 
	}
}; 



 int main(){

 	const int len = 5; 
 	int i; 
 	int a[len] = {3, 5, 6, 1 , 2}; 
 	priority_queue<int> qi; 
 	for(i = 0; i < len; i++)
 		qi.push(a[i]); 
 	for(i = 0; i < len; i++)
 	{
 		cout << qi.top() << endl; 
 		qi.pop();
 	}

  /*
    priority_queue<Node,vector<Node>,cmpLess> pq2;  
    vector<Node> b(len);  
    b[0].key = 6; b[0].value = 1;  
    b[1].key = 9; b[1].value = 5;  
    b[2].key = 2; b[2].value = 3;  
    b[3].key = 8; b[3].value = 2;  
    b[4].key = 1; b[4].value = 4;  
  
    for(i = 0; i < len; i++)  
        pq2.push(b[i]);  
    cout<<"piority"<<'\t'<<"value"<<endl;  
    for(i = 0; i < len; i++)  
    {  
        cout<<pq2.top().key<<'\t'<<pq2.top().value<<endl;  
        pq2.pop();  
    }  
    */ 
    return 0;  

 }







































