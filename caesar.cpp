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

// https://www.hackerrank.com/challenges/caesar-cipher-1
// characters modular moving problem
int main(){ 
    
    int length, shift; 
    string text;
    cin >> length >> text >> shift; 
    
    for (char & c : text) // iterate all characters  
    {
        if (isalpha(c)) {
            int offset = islower(c) ? 'a' :'A';   // offset starts from 'a' = 97 or 'A' = 65
            c = ((c-offset + shift) % 26) + offset; 
        }
    }
    cout << text << endl; 
    return 0;
}