// 136 single number 

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ret = nums[0]; 
    for(int i = 1; i < nums.size(); i++)
      {
	ret = ret ^ nums[i]; 
      }
    return ret;
  }
};
