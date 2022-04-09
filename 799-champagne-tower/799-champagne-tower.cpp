class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<double> curr(1,poured);
        
        for(int i=0;i<=query_row;i++)
        {
            vector<double> next(i+2,0);
            
            for(int j=0;j<=i;j++)
            {
                double t=curr[j];
                if(t>=1)
                {
                    next[j] += (t-1)/2;
                    next[j+1] += (t-1)/2;
                    curr[j]=1;
                }
            }
            
            if(i!=query_row) curr = next;
        }
        
    return curr[query_glass];
    }
};