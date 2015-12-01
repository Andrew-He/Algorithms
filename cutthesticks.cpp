#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// https://www.hackerrank.com/challenges/cut-the-sticks
// using some c++ 11 feature 
void RemoveSmallestDuplicate(int total, vector<int> v) {
    sort(v.begin(), v.end());  // sort it in incremental manner 
    //auto last = unique(v.begin(), v.end());  // complexity O(n log n)
    //v.erase(last, v.end()); 
    int cut_old = -1; 
    int cut_new; 
    for (auto pp : v) {
            cut_new = count_if(v.begin(), v.end(), [](int n){return n > 0;} );
            if (cut_old != cut_new) {
                cut_old = cut_new; 
                cout << cut_new << endl; 
            }
            for (auto p = v.begin(); p != v.end(); ++p ) 
            {   
                *p = *p - pp;  
            }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    RemoveSmallestDuplicate(n, arr); 
    return 0;
}