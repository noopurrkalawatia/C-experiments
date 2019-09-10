class LRUCache
{
public:
    int lruCapacity;
    list<pair<int,int>> myKeyList;
    unordered_map<int, list<pair<int, int>>::iterator> myMap;
   
    
    LRUCache(int capacity)
    {
        lruCapacity = capacity; 
    }
    
    int get(int key) 
    {
        if(myMap.find(key) == myMap.end())
        {
            return -1;
        }
        
        myKeyList.splice(myKeyList.begin(),myKeyList,myMap[key]);
        return myMap[key]->second;
    }
    
    void put(int key, int value) 
    {
        if(get(key) != -1)
        {
            myMap[key]->second = value;
            return;
        }
        
        else
        {
            if(myKeyList.size() == lruCapacity)
            {
                int resKey = myKeyList.back().first;
                myKeyList.pop_back();
                myMap.erase(resKey);
            }
            
            myKeyList.emplace_front(key,value);
            myMap[key] = myKeyList.begin();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
