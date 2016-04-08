// use bitset to implement a simple hashtable build a mapping relation between integets. 

class BitSet {
public:
	vector<int> _bitset; 
	BitSet(int size) {
		_bitset.resize( (size >> 5) + 1 ); 
	}

	bool get(int pos) {
		int wordNum = (pos >> 5);    // 2^32 bits in bitset 
		int bitNum = (pos % 32);    // to represents 2^32 as maximum 
		return (_bitset[wordNum] & (1 << bitNum)) != 0; 
	}
	void set (int pos) {
		int wordNum = (pos >> 5); 
		int bitNum = (pos % 32); 
		_bitset[wordNum] |= 1 << bitNum; 
	}

	void CheckDuplicates(vector<int> array) {
		BitSet *bs = new BitSet(32000); 
		for (int i = 0 ;  i < array.size(); ++i ) {
			int num = array[i]; 
			int num0 =  num - 1; 
			if (bs -> get(num0)) {
				cout << num << endl; 
			} else {
				bs -> set(num0); 
			}
		}
	}
}; 




/*
// with array range in [1, 32000]
int main() {
	vector<int> arr = {1,2,2,3,31000}; 
	BitSet bs(10000); 
	bs.CheckDuplicates(arr);
	return 0; 
}
*/


