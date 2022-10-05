class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n=colors.size();
        
        int res=0;
        int currCost=0;
        int maxCost=0;
        
        for(int i=0;i<n;i++) {
            
            if(i-1>=0 && colors[i]!=colors[i-1]) {
                res+= currCost-maxCost;
                currCost=0;
                maxCost=0;
            }
            currCost+=neededTime[i];
            maxCost=max(maxCost,neededTime[i]);  
        }
         res+= currCost-maxCost;
        
        return res;
        
    }
};