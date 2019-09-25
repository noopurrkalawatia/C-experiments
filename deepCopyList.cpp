/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        
        Node *temp = head;
        while(temp != NULL)
        {
            Node* newNode = new Node(temp->val, temp->next, NULL);
            temp->next = newNode;
            temp = newNode->next;
        }
        
        temp = head;
        
        while(temp != NULL)
        {
            if(temp->random == temp)
            {
                temp->next->random = temp->next;
            }
            else if(temp->random == NULL)
            {
                temp->next->random = NULL;
            }
            else
            {
                temp->next->random = temp->random->next;
            }
            
            temp = temp->next->next;
        }
        
        Node* head2;
        temp = head;
        head2 = temp->next;
        Node* temp2 = head2;
        
        while(temp != NULL)
        {
            temp->next =  temp2->next;
            if(temp->next)
            {
                temp2->next = temp->next->next;
            }
            
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return head2;
    }
};
