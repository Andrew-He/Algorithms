
/** 83. Remove Duplicates from Sorted List
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 }*/

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* prev = nullptr; 
    ListNode* cur = head; 
    // alway not delete head otherwise, need to do some trick 
    while (cur != nullptr){
      if (prev != nullptr && cur -> val == prev -> val){
	if (cur -> next != nullptr){
	  ListNode*copy = cur; 
	  prev -> next = cur -> next; 
	  cur = cur -> next; 
	  delete copy;
	}else{ // reach the end
	  prev -> next = nullptr; 
	  delete cur; 
	  break; 
	}
      }
      else {
	prev = cur; 
	cur = cur -> next; 
      }
    }
        
    return head; 
  }
};
