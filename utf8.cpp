class Solution {
public:
    bool nvalidByte(int temp)
    {
        return ((temp & 0xc0) == 128 ? true : false);
    }
    
    bool onevalidByte(int temp)
    {
        return ( (temp & 0x80) == 0 ? true : false);
    }
    
    bool nvalidByteN(const vector<int>& data, int& index) 
    {
        int count = 0;
        int nbyteCheck = 0x80;
        while(nbyteCheck & data[index])
        {
            nbyteCheck = nbyteCheck >> 1;
            ++count;
        }
        
        if (count < 2 || count > 4 || count > (data.size() - index))
        {
            return false;
        }
        --count;
        ++index;
        while(count > 0) 
        {
            if(nvalidByte(data[index]) == false)
            {
                return false;
            }
            --count;
            ++index;
        }
        return true;
    }
    
    bool validUtf8(vector<int>& data) 
    {        
        for (int i = 0; i < data.size(); ) 
        {
            if (onevalidByte(data[i])) 
            {
                ++i;
            } 
            else if (nvalidByteN(data, i) == false) 
            {
                return false;
            }
        }
        return true;
    }
};
