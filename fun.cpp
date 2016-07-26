#include <iostream>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <sys/mman.h>
#include <unordered_map>
#include <string> 
#include <iterator>
#include <thread>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std; 

std::pair<int,int> getEraseBounds(string str){
	int left = 0, right = 0;  
	while (str[right++] != '1'); 
	pair<int,int> p; 
	p = make_pair(left, right - 1);
	return p; 
}

template <typename T>
void printBinary(T a){
	int size = sizeof(a) * 8; 
	int cnt = 0; 
	string s = ""; 
	while (cnt < size){
		s.insert(0, std::to_string((a >> cnt) & 0x1));
		cnt++; 
	}
	std::pair<int,int> erasePair = getEraseBounds(s);  
	if (right > 0)
 		s.erase(s.begin() + erasePair.first, s.begin() + erasePair.second);  
 	string prefix = "0x"; 
 	s.insert(0, prefix); 
	cout << s << endl; 
}

/* play with string 
		char a[] = "hello";
        int b[] = {1, 2, 3, 4, 5};

        printf("a: %lu\n", sizeof(a));
        printf("b memory size: %lu bytes\n", sizeof(b));
        printf("b elements: %lu\n", sizeof(b)/sizeof(int));
        char *aaa = (char*)malloc(sizeof(char)*5); 
        aaa = "sgood";
        char *aa = "good"; 
        char bb[] = "good";
        printf("%p\n", aaa); 
        printf("%p\n", aa); 
        printf("%pp\n", bb); 
        printBinary(aaa[0]); 
        printf("\n%d\n", aaa[0]);  
        printBinary(aaa[0]);  
 */ 
void getLen(int &cnt, char *s){
	while ( *s != '\0'){
		s++; 
		cnt++; 
	}
}


 


    int myAtoi(string str) {
        // check valid;
        for(int i = 0; i < str.length(); i++) if (str[i] - '0' > 9) return -1; 
        
        int len = str.length(); 
        int res = 0;
        int i = 0; 
        while (len != 0){
            res += (str[i] - '0') * (len * 10); 
            i++, len--; 
        }
        
        return res; 
    }
 	auto functor = [](string s1, string s2) -> bool {  
		int i = 0; 
		while ( i != s1.length() || i != s2.length() ){
			if (s1[i] - s2[i]) return true; 
			else return false; 
		}
		return true; 
	};

	vector<vector<string>> groupAnagrams(vector<string> &list){
		vector<vector<string>> result; 
		unordered_map<string, vector<string>> map; 
		int i = 0; 
		for(string s : list ){
			sort(s.begin(), s.end()); 
			map[s].push_back( list[i++] ); 
		}
		for(auto p : map){
			sort(p.second.begin(), p.second.end()); 
			//cout << p.second << "\t"; 
			result.push_back(p.second); 
		}
		for(vector<string> list : result) {
			for(string s : list){
				cout << s << "\t"; 
			}
			cout << endl; 
		}
		return result; 
	}




/*
int main(){
	vector<int> nums = { 2, 7, 11, 15, 11};
	unordered_map<int, int> map; 
        for_each(nums.begin(), nums.end(), [&map](int num)
            {
                if (map.find(num) == map.end()){
                    map[num] = 1; 
                } else if (map.find(num) != map.end()) 
                {
                	map[num]++; 
                }
            }
        ); 

    for(auto p : map){
    	cout << p.first << " " << p.second << endl; 
    }
    return 0; 
}
*/

int BitCount(int n ){
	unsigned int c = 0; 
	for( c= 0; n; n >>= 1) {
		c += n & 0x1; 
	}
	return c; 
}


template <class T>
class A {
	T a; 
public:
	void print(){ cout << "hello"; } 
};


template <class T>
class B : public A<T> {
public:
	void print(){ cout << "hello"; } 
};


template <class T>
void oddNumber(vector<T> v){
	unordered_set<T> set;  
	
	for(int i = 0; i < v.size(); i++) {
		if ( !set.insert(v[i]).second ) {
			set.erase(v[i]); 
		}
	}
	for_each( set.begin(), set.end(), [](T elem)
		{	cout << elem << " "; }  ); 
	return; 
}
 
template <typename Iterator>
void reverse(Iterator &begin, Iterator &end){
	if (begin == end) return; 
	typename::iterator_traits<Iterator>::value_type temp = *begin; 
	*begin = *end; 
	*end = temp; 
	reverse( begin + 1, end - 1); 
}



struct Node {
	int data; 
	Node *next; 
	Node(int _data): data(_data) {}
};

class LinkedList{
	int size; 
	Node *head; 
public:
	LinkedList():size(0), head(nullptr){}
	~LinkedList(){ 
		while (head -> next != nullptr) {
			Node *node = head; 
			head = head -> next; 
			delete node; 
		}
	}
	void push(int elem){
		Node* node = head; 
		if (node == nullptr) { node = new Node(elem);  return; }
		while (node -> next != nullptr) {
			node = node -> next; 
		}
		node -> next = new Node(elem); 
	}
	void traverse(){
		Node* node = head; 
		while (node != nullptr) {
			cout << node -> data << "\t"; 
			node = node -> next; 
		}
	}
};


int max(int n){
	if (n == 2)
			return 1; 
	else if (n == 3)
			return 2; 
	else if (n % 3 == 0)
			return (int)pow(3, n/3); 
	else if (n % 3 == 1) 
			return 2 * 2 * (int)pow(3, (n - 4)/ 3); 
	else 
			return 2 * (int)pow(3, (n - 2) /3); 
}


struct Purchase 
{
	string itemId; 
	int quantity; 
	Purchase(string item, int quan)
		: itemId(item), quantity(quan) 
	{}
};

vector<string> find(vector<Purchase> list, int threshold)
{
	vector<string> res; 
	for( const Purchase pc : list )
		if ( pc.quantity > threshold ) res.push_back( pc.itemId ); 
	return res; 
}


ostream & operator << (ostream &os, vector<Purchase> pc)
{
	for( Purchase s : pc) 
		os << s.itemId << " "; 
	os << endl; 
	return os; 
}

ostream & operator << (ostream &os, vector<string> res)
{
	for( string s : res) 
		os << s << " "; 
	os << endl; 
	return os; 
}



class Pool    // global unique 
{
private:
	static Pool *instance; 
	Pool(){ value = 1; }  // user cannot instantiate a class by himself
	int value; 

public:
	static Pool *getInstance()
	{
		if (instance == nullptr) 
			instance = new Pool; 
		return instance; 
	} 
	void print()
	{
		cout << "value :" << value << endl; 
	}

	void setValue( int n)
	{
		value = n; 
	}

	Pool(Pool &rhs) = delete; 
	Pool& operator = (Pool const &rhs) = delete; 
};


Pool *Pool::instance = 0;    // avoid using this pattern most of cases
 

int majorityElement(vector<int> num) {
        int result=num[0];int len = num.size();
        int count = 0;
        for (int i=0;i<len;i++){
            if (count==0||result==num[i]) {
                result = num[i];count++;}   //count清零时，取当前数作为result
            else count--;
        }
        return result;
    }


int main()
{


}

 

 





