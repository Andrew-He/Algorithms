// 239 sliding window maximum 

class Solution {
public:
    // use deque :: double linked list 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rs;
        deque<int> dq; 
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); 
            dq.push_back(i); 
            if (i >= k -1) rs.push_back(nums[dq.front()]); 
        }
        return rs;
    }
    /* brute force O(n^2)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> rs; 
        if (nums.size() == 0) return rs; 
        for(int i = 0; i < nums.size()- k + 1; i++){
            int max = nums[i];  
            for(int j = i; j < i + k; j++ ){
                if (max < nums[j])   
                    max = nums[j]; 
            }
            rs.emplace_back(max); 
        }
        return rs; 
    }
    */
};
