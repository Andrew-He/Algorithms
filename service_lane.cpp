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
// https://www.hackerrank.com/challenges/service-lane/submissions/code/15491877 
// learn vector iterator 
int getMinElement(vector<int>, int, int); 

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        
        cout << getMinElement( width, i, j) << endl; 
    }
    return 0;
}

int getMinElement(vector<int> width, int i, int j) {
    int min = 1000; 
    for (vector<int>::iterator it = width.begin() + i; it != width.begin() + j + 1; ++it){
        if (min > *it) min = *it; 
    }
    return min; 
}