class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int sum = 0;
        int buyingIndex = 0;
        int sellingIndex = 0;
        
        while(true)
        {
            while((buyingIndex + 1 < prices.size()) && (prices[buyingIndex] > prices[buyingIndex + 1]))
            {
                ++buyingIndex;
            }
            
            sellingIndex = buyingIndex + 1;
            
            while((sellingIndex + 1 < prices.size()) && (prices[sellingIndex] < prices[sellingIndex + 1]))
            {
                ++sellingIndex;
            }
            
            if(buyingIndex >= prices.size() || sellingIndex >= prices.size())
            {
                break;
            }
            
            sum += prices[sellingIndex] - prices[buyingIndex];
            buyingIndex = sellingIndex + 1;
        }
        return sum;
    }
};
