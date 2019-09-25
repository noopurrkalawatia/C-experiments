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
    bool hasCycle(ListNode *head) 
    {
        ListNode* slw = head;
        ListNode* fast = head;
        
        while(slw && fast && fast->next != NULL)
        {
            slw = slw->next;
            fast = fast->next->next;
            
            if(slw == fast)
            {
                return true;
            }
        }
        return false;
    }
};
