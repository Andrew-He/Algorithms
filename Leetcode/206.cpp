
// 206 leetcode reverse singlely linked list 
// O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    	ListNode *new_head = nullptr; 

    	while (head !=nullptr){
    		ListNode* next = head -> next; 
    		head -> next = new_head; 
    		new_head = head; 
    		head = next; 
    	}
    	return new_head; 
    }
};