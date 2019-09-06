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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int length1 = 0, difference;
        struct ListNode *temp1,*temp2;
        
        temp1 = headA;
        while(temp1 != NULL)
        {
            length1++;
            temp1 = temp1->next;
        }
        
        temp2 = headB;
        int length2 = 0;
        while(temp2 != NULL)
        {
            length2++;
            temp2 = temp2->next;
        }
        
        if(length1 > length2)
        {
            difference = length1 - length2;
            temp1 = headA;
            temp2 = headB;
        }
        
        else
        {
            difference = length2 - length1;
            temp1 = headB;
            temp2 = headA;
        }
        
        if(difference == 0)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            return NULL;
        }
        
        else
        {
            while(difference != 0)
            {
                temp1 = temp1->next;
                difference--;
            }
        
            while(temp1!= NULL && temp2 != NULL)
            {
                if(temp1->next == temp2->next)
                {
                    return temp1->next;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return NULL;    
        }
        
        
    }
};
