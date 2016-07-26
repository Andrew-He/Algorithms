/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode *prev = nullptr; 
        ListNode *cur = head; 
        
        while (cur != nullptr)
        {
            if (prev != nullptr && prev -> val == cur -> val)
            {
                prev -> next = cur -> next; 
                ListNode *node = cur; 
                cur = cur -> next; 
                delete node; 
                continue; 
            }
            prev = cur; 
            cur = cur -> next; 
        }
        return head; 
    }
};