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

typedef unsigned int size_t; 
// https://www.hackerrank.com/challenges/the-grid-search/copy-from/15491665
// How to use string vector in C++
void isSubGrid(vector<string> &bigGrid, vector<string> &smallGrid) 
{
    for (int i = 0; i < bigGrid.size() - smallGrid.size() + 1; i++) 
    {
        size_t pos = 0;
        size_t found;
        while (pos < bigGrid[i].size()
               && (found = bigGrid[i].find(smallGrid[0], pos)) != string::npos)
        {   
            bool flag = true;
            for (int j = 1; j < smallGrid.size(); j++)  // iterate row by row 
            {
                if (bigGrid[i+j].substr(found, smallGrid[j].size()) != smallGrid[j])   // subtr to to match each row by smallGrid
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
                return;
            }

            pos = found + 1;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);    
        for(int G_i = 0; G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        isSubGrid(G, P);
              
    }
    return 0;
}