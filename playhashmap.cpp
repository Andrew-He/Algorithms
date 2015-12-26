#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <random>
#include <typeindex>
#include <numeric>

using namespace std; 

typedef pair<string, int> Pair; 
ostream& operator<< (ostream&  out, const Pair& p) 
{	return out << p.first << "\t" << p.second;   }

template <class T1>
struct compareByKeyLen {	
	bool operator()(const T1 &s1, const T1 &s2)
	{	return s1.length() <= s2.length()?true:false;   }
};

template<class T1>
struct compareByValue
{
    bool operator()(const T1 &lhs, const T1 &rhs)
    {  return lhs.second<=rhs.second ? true:false;   }
};


template <class T1, class T2>
pair<T1, T2> make_pair_implementation(T1 x, T2 y){
	return pair<T1, T2>(x, y); 
}


template <typename T>
void print_for_each(vector<T> v, std::function<void (T)> func){
    std::for_each(v.begin(), v.end(), func); 
}


int main() {
	vector<int> v(10); 
	iota( v.begin(), v.end(), 0); 

	auto printElement = [](int y) { 
    	std::cout << y << " "; 
	}; 
	//print_for_each<int>(v, printElement);
	std::random_device rd; 
	std::mt19937 gen(rd());			// get seed 
	std::uniform_int_distribution<> dis(0,25); // generate uniform dist of 1 - 26  

	vector<string> strList;

	for (int i = 0; i < dis(gen) + 1; ++i) {
		string temp = ""; 
		for (int j = 0; j < dis(gen) + 1; ++j) 
		{  
			temp.insert( temp.end(),  static_cast<char>('a' + dis(gen))); 
			// temp.append( static_cast<char>('a' + dis(gen)) ); 
		}
		strList.push_back( temp ); 
	}

	int i = 1; 
	for(auto p : strList) {
		cout << i <<"th string is " << p << endl;  
		++i; 
	}
	
	strList.clear(); 
	return 0; 
}



/*

int main() {
	unordered_map<string,int> map; 
	map.insert(make_pair("book", 24));
	map.insert(make_pair("sword", 33)); 
	map.insert(make_pair("man", 44));
	map.insert(make_pair("man", 40));   // collision by key 
	map.insert(make_pair("man", 44));   // collision by key 
	vector<Pair> vec(map.begin(), map.end()); 
//	sort( vec.begin(), vec.end(), compareByValue<Pair>() ); 
	sort( vec.begin(), vec.end(), [](Pair p1, Pair p2) -> int { return p1.second < p2.second; } );  
 
	for_each( vec.begin(), vec.end(), []( Pair p) { cout << p.first << "\t" << p.second << endl; }); 
	
	// p is std::__1::pair<std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >, int>
	// for (auto p : vec) cout << p << endl  // << typeid(p).name() << endl; 
	

	return 0; 
}
*/

