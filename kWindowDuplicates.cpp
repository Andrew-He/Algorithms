#include <iostream>
#include <unordered_set>
#include <vector>
#include <dequeue>

using namespace std ;

class KWindows 
{
	int _nDuplicates; 

public:
	KWindows(int nDuplciates)
		: _nDuplicates(nDuplciates)
	{}
	~KWindows() {}

	void nDuplictesByIteration( vector<int> list,  int winSize )
	{
		if (winSize < list.size()) return; 
		dequeue<int> dq; 
		unordered_set<int> checkList; 
		int i; 
		for(i = 0; i < winSize; i++) 
		{
			if ( !checkList.insert( list[i] ).second ) _nDuplicates++;
			dq.push_back( list[i] ); 
		}
		int iteration = 1; 
		cout << "iteration 1 : " << _nDuplicates << endl;  
		for(int j = i + 1; j < list.size(); j++)
		{
			if ( checkList.find( dq.front() ) != checkList.end() )
				_nDuplicates--; 
			dq.pop_front(); 
			dq.push_back( list[i] );
			if ( ! checkList.insert( list[i] ).second ) 
				_nDuplicates++; 
			
			cout << "iteration " <<  iteration++  << ": " << _nDuplicates << endl; 
		}
	}

};


int main(){
	A a("hello"); 

	
	return 0; 


}






