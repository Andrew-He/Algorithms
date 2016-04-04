#include <iostream>
#include <vector> 
#include <utility>
#include <unordered_set>

using namespace std; 


// optimal substructure: 1. item is in the subset  2. item is not in the optimal subset 
						// max value is obtained by m-1 items and W weight   case 1
// value of nth item + max_value from n -1 items and W - weight of nth item 
// if weight of nth item > W, then nth item cannot be included and case 1 is the only possible 

int knap(int W, int wt[], int val[], int n){
	if ( n == 0 || W == 0 )
		return 0; 
	if ( wt[n-1] > W )
		return knap(W, wt, val, n - 1);  

	else return max( val[n-1] + knap(W - wt[n-1], wt, val, n - 1 ), knap(W, wt, val, n - 1) ); 
}  

int main(){
	int val[] = {60, 100, 120};
	int wt[] = { 10, 20 , 30};

	int W = 30;

	int n = 3;
	cout << knap(W, wt, val, n) << endl;

	return 0; 

}




 