class Solution 
{
private:
    
    void updateSkyline(vector<vector<int>> &output, int x, int maxY)
    {
        if(output.size() == 0 || output.back()[0] != x)
        {
            vector<int> temp{x,maxY};
            output.push_back(temp);
        }
        else
        {
            output.back()[1] = maxY;
        }
    }
    
        void appendSkyline(vector<vector<int>>& output, vector<vector<int>> skyLine,int start,int end, int currY)
    {
        while(start < end)
        {
            vector<int> point = skyLine[start];
            
            int x = point[0];
            int y = point[1];
            
            ++start;
            
            if(y != currY)
            {
                updateSkyline(output,x,y);
                currY = y;
            }
        }
    }
        
    vector<vector<int>> mergeSkyline(vector<vector<int>> leftSkyline, vector<vector<int>> rightSkyline)
    {
        vector<vector<int>> output;
        int nL = leftSkyline.size();
        int nR = rightSkyline.size();
        int pL = 0;
        int pR = 0;
        
        int x = 0;
        int maxY = 0;
        int currY = 0;
        int leftY = 0;
        int rightY = 0;
        
        while((pL < nL) && (pR < nR))
        {
            vector<int> pointL = leftSkyline[pL];
            
            vector<int> pointR = rightSkyline[pR];
            
            if(pointL[0] < pointR[0])
            {
                x = pointL[0];
                leftY = pointL[1];
                ++pL;
            }
            else
            {
                x = pointR[0];
                rightY = pointR[1];
                ++pR;
            }
            
            maxY = max(leftY,rightY);
            
            if(currY != maxY)
            {
                updateSkyline(output,x,maxY);
                currY = maxY;
            } 
        }
        
        appendSkyline(output,leftSkyline,pL,nL,currY);
        appendSkyline(output,rightSkyline,pR,nR,currY);
        
        return output;
    }
        
    void copyVector(const vector<vector<int>> buildings, vector<vector<int>> &particular,
                   int start, int end)
    {
        for(int i = start; i < end; ++i)
        {
            vector<int> temp;
            copy(buildings[i].begin(), buildings[i].end(), back_inserter(temp));
            particular.push_back(temp);
        }
    }
    
    public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<vector<int>> result;
        int n = buildings.size();
        if(buildings.size() == 0)
        {
            return result;
        }
        
        if(buildings.size() == 1)
        {
            vector<int> temp;
            int xStart = buildings[0][0];
            int xEnd = buildings[0][1];
            int y = buildings[0][2];
            
            vector<int> start{xStart,y};
            vector<int> end{xEnd,0};
            result.push_back(start);
            result.push_back(end);
            
            return result;
        }
        
        vector<vector<int>> left;
        copyVector(buildings,left,0,n/2);
        
        vector<vector<int>> right;
        copyVector(buildings,right,n/2,n);
        
        vector<vector<int>> leftSkyline = getSkyline(left);
        vector<vector<int>> rightSkyline = getSkyline(right);
        
        return mergeSkyline(leftSkyline,rightSkyline);
    }
    
};
