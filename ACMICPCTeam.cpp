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
// https://www.hackerrank.com/challenges/acm-icpc-team/submissions/code/15493814
// play with string
int bothKnow(string s1, string s2){
    int nTopics = 0; 
    for(int i = 0; i < s1.size(); ++i) {
    	if (s1[i] == '1' || s2[i] == '1') nTopics++; 
    }
    return nTopics; 
}

void solution(vector<string> topic) {
	int max = 0;  
	int tmp; 
	int team = 0; 
	for (int i = 0; i < topic.size(); i++) 
		for (int j = i + 1; j < topic.size(); j++ ) 
		{
			tmp = bothKnow(topic[i], topic[j]);    // or topic.at(i)
			if (tmp > max) {
				max = tmp; 
				team = 1;  
			} else if (max == tmp){
				team += 1; 
			}
		}
	cout << max << endl; 
	cout << team << endl; 

}


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    solution(topic); 
    return 0;
}