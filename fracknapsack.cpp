#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int weight;
    int value;

};

bool compareItem(struct item i1,struct item i2)
{
    double ratio1 = (double)i1.value / i1.weight;
    double ratio2 = (double)i2.value / i2.weight;
        
    return(ratio1 > ratio2);
}

double knapsack(struct item totalItems[],int size, int weightSack)
{
    sort(totalItems,totalItems+size,compareItem);
    
    double currentValue = 0;
    int currentWeight = 0;
    
    for(int i = 0 ; i < size; ++i)
    {
        if(currentWeight + totalItems[i].weight <= weightSack)
        {
            currentWeight += totalItems[i].weight;
            currentValue += totalItems[i].value;
        }
        
        else
        {
            int remain = weightSack - currentWeight;
            currentValue += totalItems[i].value * ((double) remain / totalItems[i].weight);
            break;
        }
    }
    
    return currentValue;
}

int main() 
{
	int noOfTestcases = 0,value = 0, weight = 0;
	
	cin >> noOfTestcases;
	for(int i = 0 ; i < noOfTestcases; ++i)
	{
	    int ipPara[2];
	    
	    for(int j = 0 ; j < 2; ++j)
	    {
	        cin >> ipPara[j];
	    }
	    
	    int itemsSize = ipPara[0];
	    int weightBag = ipPara[1];
	    
	    struct item totalItems[itemsSize];
	    
	    for(int i = 0 ; i < itemsSize; ++i)
	    {
	        cin >> totalItems[i].value;
	        cin >> totalItems[i].weight;
	    }
	    
	    
	    double result = knapsack(totalItems,itemsSize,weightBag);
	    
	    printf ("%.2f",result);
	    printf("\n");
	}
	return 0;
}
