/**
 * 102. Binary Tree Level Order Travelsal   
 *    (non-recursive solution)
 * Definition for a binary tree node.
 */  
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

#include <queue> 
#include <vector>
using namespace std;  
typedef vector<vector<int>> RS;  
typedef vector<int> Level; 


class Solution {
public:

      RS levelOrder(TreeNode *root){ 
          if (root == nullptr) return RS(); 
          RS rs;  
          queue<TreeNode*> q; 
          q.push(root);  
          
          while (!q.empty()) {
              Level level;         
              int size = q.size(); 
              for(int i = 0; i < size; i++){
                  TreeNode *temp = q.front(); 
                  level.push_back( temp -> val );   // 1 2 3 | 4 5 6 7
                  if (temp -> left != nullptr)
                    q.push(temp -> left); 
                  if (temp -> right != nullptr)
                    q.push(temp -> right); 
                  q.pop(); 
            } 
            rs.push_back(level); 
          }
          return rs; 
      }    
};


int main() {
  return 0; 
}