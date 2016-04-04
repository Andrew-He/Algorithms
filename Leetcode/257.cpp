//Binary TreePath (DFS)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_set> 
#include <stack>

typedef vector<string> Paths; 
typedef string Path; 

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        Paths paths; 
        if (root == nullptr) return paths; 
        sub(paths, root, to_string(root->val)); 
        return paths; 
    }
    
    void sub(Paths &paths, TreeNode* node, Path path){
        if (node -> left == nullptr && node -> right == nullptr){
            paths.push_back(path); 
            return; 
        }
        if (node -> left != nullptr) sub(paths, node -> left, path + "->" + to_string(node ->left -> val));
        if (node -> right != nullptr) sub(paths, node -> right, path + "->" + to_string(node-> right->val)); 
    }
    
};



