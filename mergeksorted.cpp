/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class myComparator
{
    public:
    int operator() (const ListNode* p, const ListNode* q)
    {
        return(p->val > q->val);
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* result = NULL; 
        ListNode* temp = NULL;
        priority_queue<ListNode*, vector<ListNode*>, myComparator> myQueue;
        
        for(int i = 0 ; i < lists.size(); ++i)
        {
            if(lists[i] != NULL)
            {
                myQueue.push(lists[i]);
            }
        }
        
        while(!myQueue.empty())
        {
            ListNode* current = myQueue.top();
            myQueue.pop();
            
            if(current->next != NULL)
            {
                myQueue.push(current->next);
            }
            
            if(result == NULL)
            {
                result = current;
                temp = current;
            }
            
            else
            {
                temp->next = current;
                temp = temp->next;
            }    
        }
        
        return result;
    }
};
