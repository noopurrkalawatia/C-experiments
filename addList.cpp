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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* result = NULL;
        ListNode* temp = NULL;
 
        int sum = 0, carry = 0;
        
        if(second->val == 0 && second->next == NULL)
        {
            return first;
        }
        
        if(first->val == 0 && first->next == NULL)
        {
            return second;
        }
        
        while(first != NULL || second != NULL)
        {
            sum = ((first) ? first->val : 0 ) + ((second) ? second->val : 0) +                   carry;

            carry = sum / 10; 
            sum = sum % 10;  
            
            ListNode* current = new ListNode(sum);
            
            if(result == NULL)
            {
                result = current;
                temp = result;
            }
                
            else
            {
                temp->next = current;
                temp = temp->next;
            }
            
            first = first ? first->next : NULL;
            second = second ? second->next : NULL;
        } 
        
        if(carry)
        {
            ListNode* current = new ListNode(carry);
            temp->next = current;
        }
        
        return result;
    }
    
    
};
