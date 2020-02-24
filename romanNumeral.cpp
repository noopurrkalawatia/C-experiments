class Solution {
public:
    string intToRoman(int num) 
    {
        map<int,string> myMap;
        myMap[1] = "I";
        myMap[2] = "II";
        myMap[3] = "III";
        myMap[4] = "IV";
        myMap[5] = "V";
        myMap[6] = "VI";
        myMap[7] = "VII";
        myMap[8] = "VIII";
        myMap[9] = "IX";
        myMap[10] = "X";
        myMap[20] = "XX";
        myMap[30] = "XXX";
        myMap[40] = "XL";
        myMap[50] = "L";
        myMap[60] = "LX";
        myMap[70] = "LXX";
        myMap[80] = "LXXX";
        myMap[90] = "XC";
        myMap[100] = "C";
        myMap[200] = "CC";
        myMap[300] = "CCC";
        myMap[400] = "CD";
        myMap[500] = "D";
        myMap[600] = "DC";
        myMap[700] = "DCC";
        myMap[800] = "DCCC";
        myMap[900] = "CM";
        myMap[1000] = "M";
        myMap[2000] = "MM";
        myMap[3000] = "MMM";
        
        int numTemp = num;
        string myResult;
        
        int thousandNum = (numTemp / 1000);
        numTemp = numTemp - (thousandNum * 1000);
        
        int hundredNum = numTemp / 100 ; 
        numTemp = numTemp - (hundredNum * 100);
        
        int tensNum = (numTemp / 10 );
        int units = numTemp - (tensNum * 10);
        
        if(thousandNum > 3)
        {
            return "M";
        }
        
        if(thousandNum >= 1)
        {
            auto it = myMap.find(thousandNum * 1000);
            if(it != myMap.end())
            {
                myResult += it->second;
            }
        }
            
        if(hundredNum >= 1)
        {
            auto it = myMap.find(hundredNum * 100);
            if(it != myMap.end())
            {
                myResult += it->second;
            }
        }
        
        if(tensNum >= 1)
        {
            auto it = myMap.find(tensNum * 10);
            if(it != myMap.end())
            {
                myResult += it->second;
            }
        }
        
        if(units >= 1)
        {
            auto it = myMap.find(units);
            if(it != myMap.end())
            {
                myResult += it->second;
            }
        }
        
        return myResult;
    }
};
