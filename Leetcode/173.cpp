/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
class BSTIterator {
private:
    stack<TreeNode*> stk; 
    TreeNode *cur;
public:
    BSTIterator(TreeNode *root) {
        cur = root; 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (cur!=nullptr || !stk.empty());  
    }

    /** @return the next smallest number */
    int next() {
        while (cur != nullptr) {
            stk.push(cur);    
            cur = cur -> left; 
        }
        cur = stk.top(); 
        stk.pop(); 
        TreeNode *node = cur;
        cur = cur -> right;

        return node -> val;

        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */