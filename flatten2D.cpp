class Vector2D 
{
    private:
    vector<vector<int>> _v;
    size_t size;
    int globalIndex; 
    int currentIndex;
    int tempIndex;
    
    void findValidIndex()
    {
        do
        {
            ++globalIndex;
        }while((globalIndex < size) && _v[globalIndex].size() == 0);
    }
    
public:
    Vector2D(vector<vector<int>>& v) 
    {
        _v = v;
        size = v.size();
        tempIndex = 0;
        currentIndex = 0;
        globalIndex = 0;
        findValidIndex();
    }
    
    int next() 
    {
        int val = 0;

        if(tempIndex < _v[currentIndex].size())
        {
            val =  _v[currentIndex][tempIndex];
            ++tempIndex;
        }
        
        else
        {
            currentIndex = globalIndex;
            tempIndex = 0;
            findValidIndex();
            
            if(currentIndex == size)
            {
                return -1;
            }
            else
            {
                val = _v[currentIndex][tempIndex];
                ++tempIndex;
            }
        }
        return val;
    }
    
    bool hasNext() 
    {
        if((size != 0 && tempIndex < _v[currentIndex].size()) || (globalIndex < size))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
