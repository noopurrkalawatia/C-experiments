// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator 
{
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int currentElement;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
        currentElement = INT_MIN;
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        if(currentElement == INT_MIN && false != Iterator::hasNext())
        {
            currentElement = Iterator::next();
        }
        return currentElement;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
        if(currentElement != INT_MIN)
        {
            int temp = currentElement;
            currentElement = INT_MIN;
            return temp;
        }
        currentElement = INT_MIN;
        return(Iterator::next());
	}

	bool hasNext() const 
    {
	    if((currentElement != INT_MIN))
        {
            return true;
        }
        return Iterator::hasNext();
	}
};
