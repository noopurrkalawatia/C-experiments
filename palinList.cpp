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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slwPtr = head;
        ListNode* fastPtr = head;
        
        if(head == NULL)
        {
            return true;
        }
        
        while(fastPtr != NULL && fastPtr->next!= NULL)
        {
            fastPtr = fastPtr->next->next;
            slwPtr = slwPtr->next;
        }
        
        ListNode* start2 = reverse(slwPtr);
        
        while(head != NULL && start2 != NULL)
        {
            if(head->val != start2->val)
            {
                return false;
            }
            
            head = head->next;
            start2 = start2->next;
        }
        
        return true;
        
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        
        return prev;
    }
};
