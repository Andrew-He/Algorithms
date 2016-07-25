// 191 Number of 1 Bits : Hamming weight

class Solution {
public:
  int hammingWeight(uint32_t n) {  
    int map[] = {0, 1, 1, 2,1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}; 
    int ret = 0; 
    for(int i = 0; i <= 8; i++)
      {
	ret = ret + map[ n & 0xf ];  
	n >>= 4; 
      }
    return ret; 
  }
};
