
class HashItem{
	int key, val; 
public:
	HashItem(int k, int k): key(k), val(v){}
	const int& getKey() {
		return key; 
	}
	const int& getVal() {
		return val; 
	}
};

class HashTable {
	static const int SIZE = 256; 
	HashItem ** table; 
public:
	HashTable(){
		table = new HashItem*[SIZE](); 
	}
	void set(key, val){
		int idx = key % SIZE; 
		if (table[idx]) delete table[idx]; 
			table[idx] = new HashItem(key, val); 
	}
	const int get(key) {
		int idx = key % SIZE; 
		return table[idx] ? table[idx] - > getVal() : -1; 
	}
	~HashTable() {
		for (int i = 0; i < SIZE; i++) 
			if (table[i]) delete table[i]; 
			delete[] table; 
	}
};