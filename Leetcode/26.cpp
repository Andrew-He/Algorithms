// 26.Remove Duplicates from Sorted Array

class Solution {
public:
       
    
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <=1 ) return nums.size(); 
        int pos = 0; 
        
        for(int i = 0; i < nums.size()-1; i++){
            if (nums[i] != nums[i+1])
                nums[++pos] = nums[i+1];
        }
        return pos+1;
    }
};
