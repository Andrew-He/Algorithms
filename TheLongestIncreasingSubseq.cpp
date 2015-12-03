#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void printSizeofLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            if (find(v.begin(), v.end(), a) != v.end()) continue;
            auto it = upper_bound(v.begin(), v.end(), a);    
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        cout << v.size();
    }

int main() {
    vector<int> list;
    int n; 

    while (cin >> n) {
        list.push_back(n); 
    } 
    
    printSizeofLIS(list);    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

