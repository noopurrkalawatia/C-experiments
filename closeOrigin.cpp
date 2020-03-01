struct point
{
    int x_coordinate;
    int y_coordinate;
    float distance;
    
    point(int _x, int _y)
    {
        x_coordinate = _x;
        y_coordinate = _y;
        distance = 0; 
    }
};

void calculateDistance(point& point1)
{
    struct point point2(0,0);
    long res = pow(abs(point1.x_coordinate - point2.x_coordinate),2) + pow(abs(point1.y_coordinate - point2.y_coordinate),2);
        
    point1.distance = sqrt(res);
    return;
}

class myComparator
{
    public:
    bool operator() (point& point1, point& point2)
    {
        if(point1.distance < point2.distance)
        {
            return true;
        }
        return false;
    }
};


class Solution 
{
public:
        
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
{
    vector<vector<int>> result;
    priority_queue<point, vector<point>, myComparator> myQueue;
    
    vector<point> myPoints;
    
    for(auto p: points)
    {
        struct point temp(p[0],p[1]);
        calculateDistance(temp);
        myPoints.push_back(temp);
    }
    
    int count = 1;
    for(auto point : myPoints)
    {
        if(count <= K)
        {
            myQueue.push(point);
            ++count;
        }
        
        else
        {
            if((myQueue.top().distance > point.distance))
            {
                myQueue.pop();
                myQueue.push(point); 
            }
        }
    }
    
    while(K > 0)
    {
        vector<int> temp;
        point ptTemp = myQueue.top();
        myQueue.pop();
        temp.push_back(ptTemp.x_coordinate);
        temp.push_back(ptTemp.y_coordinate);
        result.push_back(temp);
        --K;
    }    
    return result;
}  
};
