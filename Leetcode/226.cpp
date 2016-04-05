// 226. Invert Binary Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    // iterative solution  : swap nodes on same level
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root; 
        queue<TreeNode*> q; 
        q.push(root); 
        
        while(!q.empty()){
            TreeNode *node = q.front(); 
            q.pop(); 
            if (node -> left != nullptr) 
                q.push(node -> left); 
            if (node -> right != nullptr) 
                q.push(node -> right); 
            
            if (node -> left != nullptr || node -> right != nullptr){
                TreeNode *temp = node -> left; 
                node -> left = node -> right; 
                node -> right = temp; 
            }
        }
        
        return root; 
        
    }
    // recursive solution 
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr; 
        
        TreeNode *temp = root -> left; 
        root -> left = root -> right; 
        root -> right = temp; 
        
        if (root -> left != nullptr)
            invertTree(root -> left); 
        if (root -> right != nullptr) 
            invertTree(root -> right);
        
        return root; 
    }

};


