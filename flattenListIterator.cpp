/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    stack<NestedInteger> mynestedListStack;
    int currentIndex;
    NestedIterator(vector<NestedInteger> &nestedList) 
    {        
        for(int i = nestedList.size() - 1; i >= 0 ; --i)
        {
            mynestedListStack.push(nestedList[i]);
        }
    }

    int next() 
    {
        int temp = mynestedListStack.top().getInteger();
        mynestedListStack.pop();
        return temp;
    }

    bool hasNext() 
    { 
        cout << mynestedListStack.size() << endl;
        if(mynestedListStack.size() > 0)
        {
            while(!mynestedListStack.empty() && !mynestedListStack.top().isInteger())
            {
                NestedInteger top = mynestedListStack.top();
                mynestedListStack.pop();
                
                vector<NestedInteger> topList = top.getList();
                
                for(int i = topList.size() - 1 ; i >= 0 ; --i)
                {
                    mynestedListStack.push(topList[i]);
                }
            } 
        }
        
        return !mynestedListStack.empty() ;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
