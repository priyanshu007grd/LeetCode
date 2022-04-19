class Solution {
public:
    int mctFromLeafValues(vector<int>& v) 
    {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n-1;i++) dp[i][i+1]=v[i]*v[i+1];
        for(int l=2; l<n; l++) 
        {
            for(int i=0; i+l<n;i++) 
            {
                int j=i+l;
                
                for(int k=i; k<j; k++) 
                {
                    int x = dp[i][k];
                    int y = dp[k+1][j];
                    int t = x + y + *max_element(v.begin()+i,v.begin()+k+1) * *max_element(v.begin()+k+1,v.begin()+j+1);
                    dp[i][j] = dp[i][j]==0 ? t : min(dp[i][j],t);
                }
            }
        }
        return dp[0][n-1];
    }
};