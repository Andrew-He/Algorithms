/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st; 
        ListNode *cur = head; 
        while (cur != nullptr ) { st.push( cur -> val);  cur = cur -> next; }
        cur = head; 
        while (cur != nullptr) { if ( cur -> val != st.top() ) return false; st.pop();  cur = cur -> next;  }
        return true; 
    }
};