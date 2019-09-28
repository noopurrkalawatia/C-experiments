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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == nullptr)
        {
            return NULL;
        }
        
        if(head->next == nullptr)
        {
            return head;
        }
        
        ListNode *prev = nullptr;
        ListNode *next = head->next;
        ListNode *current = head;
        
        while(current != nullptr && current->next != nullptr)
        {
            if((current->val == next->val))
            {
                if((next != nullptr) && prev != nullptr)
                {
                    while(next != nullptr && current->val == next->val)
                    {
                       next = next->next;
                    }
                    prev->next = next;  
                }
                else
                {
                    while(next != nullptr && current->val == next->val)
                    {
                        next = next->next;
                    }
                    head = next ? next : prev;   
                }
            }
            else
            {
                prev = current; 
            }
            
            current = next;
            next = current ? current->next : nullptr;
        }
        
        return head;
    }
};
