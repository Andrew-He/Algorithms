// 27. Remove Element 
/*
	Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2 

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0; 
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] != val)
                nums[cnt++] = nums[i]; 
        }
        return cnt; 
    }
};
