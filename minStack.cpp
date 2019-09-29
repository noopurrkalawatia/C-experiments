class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        myStack.push(x);
        if(minStack.size() == 0)
        {
            minStack.push(x);
        }
        else
        {
            if(x <= minStack.top())
            {
                minStack.push(x);
            }
            else
            {
                int ele = minStack.top();
                minStack.push(ele);
            }
        }
    }
    
    void pop() 
    {
        if(0 != myStack.size())
        {
            myStack.pop();
            minStack.pop();
        }
    }
    
    int top() 
    {
        int res = myStack.top();
        return(res);
    }
    
    int getMin() 
    {
        if(minStack.size() != 0)
        {
            int res = minStack.top();
            return res;
        }

        return 0;
    }
    
    private:
    stack<int> myStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
