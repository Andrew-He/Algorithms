
//64. Minimum Path Sum  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

class Solution {
public:
  // state transfer equation dp[i][j] = MIN(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j]
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() <= 0 )return 0; 
        int i, j; 
        for( i = 0; i < grid.size(); i++){
            for(j = 0; j < grid[i].size(); j++){
                int top = i - 1 < 0 ? INT_MAX : grid[i-1][j]; 
                int left = j - 1< 0 ? INT_MAX : grid[i][j-1];   
                if (top == INT_MAX && left == INT_MAX) continue; 
                grid[i][j] += (top < left ? top : left ); 
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1]; 
    }
};