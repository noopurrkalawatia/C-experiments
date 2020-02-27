class myComparator
{
    public:
   bool operator() (pair<string,int>& pair1, pair<string,int>& pair2)
    {
        if(pair1.second < pair2.second)
        {
            return false;
        }
        else if(pair1.second == pair2.second)
        {
            return pair1.first < pair2.first;
        }
        return true;
    }
};


class Solution {
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        vector<string> result;
        unordered_map<string,int> myMap;
        priority_queue<pair<string,int>, vector<pair<string,int>>, myComparator> myQueue;
        
        for(auto it : words)
        {
            if(myMap.find(it) != myMap.end())
            {
                ++myMap.at(it);
            }
            else
            {
                myMap[it] = 1;
            }
        }
        
        int count = 1;
        for(auto it = myMap.begin(); it != myMap.end(); ++it)
        {
            if(count <= k)
            {
                myQueue.push(make_pair(it->first,it->second));
                ++count;
            }
            else
            {

                if(myQueue.top().second < it->second)
                {
                    myQueue.pop();
                    myQueue.push(make_pair(it->first,it->second));
                }
                
                else if(myQueue.top().second == it->second)
                {
                    if(it->first < myQueue.top().first)
                    {
                        myQueue.pop();
                        myQueue.push(make_pair(it->first,it->second));
                    }
                }
            }
        }
        
        while(!myQueue.empty())
        {
            pair<string,int> temp = myQueue.top();
            result.push_back(temp.first);
            myQueue.pop();
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};
