class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) 
    {
        qsize = size;
        sum = 0.0; 
    }
    
    double next(int val) 
    {
        double average = 0.0;
        
        if(myQueue.size() >= qsize)
        {
            sum -= myQueue.front();
            myQueue.pop();
        }
            
        sum += val;
        myQueue.push(val);
        average = sum / myQueue.size();
        return average;
    }
    
    private:
    double sum;
    int qsize;
    queue<int> myQueue;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
