class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(myMap.find(val) != myMap.end())
        {
               return false;
        }
        nums.emplace_back(val);
        myMap[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        if(myMap.find(val) != myMap.end())
        {
            int last = nums.back();            
            myMap[last] = myMap[val];
            nums[myMap[val]] = last;
            nums.pop_back();
            myMap.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        return(nums[rand() % nums.size()]);
    }
    
    private:
    unordered_map<int, int> myMap;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
