#define TIMECONSTANT 9
class Logger {
public:
    unordered_map<string,int> myMap;
    /** Initialize your data structure here. */
    Logger() 
    {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) 
    {
        auto it = myMap.find(message);
        if(it == myMap.end())
        {
            myMap[message] = timestamp;
            return true;
        }
        else
        {
            int time = it->second;
            if(timestamp > time + TIMECONSTANT)
            {
                myMap[message] = timestamp;
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
