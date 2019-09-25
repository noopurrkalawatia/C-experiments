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
        if(l1->val == 0 && l1 == NULL)
        {
            return l2;
        }
        
        if(l2->val == 0 && l2 == NULL)
        {
            return l1;
        }
        
        ListNode* newHead1 = reverseList(l1);        
        ListNode* newHead2 = reverseList(l2);
        cout << endl;
        ListNode* result = NULL;

        ListNode* temp3 = NULL;
        int sum = 0,carry = 0;
        
        while(newHead1 != NULL || newHead2 != NULL)
        {
            sum = ((newHead1 ? newHead1->val : 0 )+ (newHead2 ? newHead2->val : 0) + carry);
                    
            carry = sum / 10;
            
            ListNode* newNode = new ListNode(sum % 10);
            
            if(result == NULL)
            {
                result = newNode;
                temp3 = result;
            }
            
            else
            {
                temp3->next = newNode;
                temp3 = temp3->next;
            }
            
            newHead1 = newHead1 ? newHead1->next : NULL;
            newHead2 = newHead2 ? newHead2->next : NULL;
        }
        
        if(carry)
        {
            temp3->next = new ListNode(carry);
        }
        
        return reverseList(result);
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* current = head;
        
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
