class Solution {
public:
    int minInsertions(string s) 
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        //for(int i=0;i<n;i++) dp[i][i]==0;
        
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i+l-1<n;i++)
            {
                int j=i+l-1;
                
                if(i==j) dp[i][j]=0;
                else if(i+1==j) dp[i][j]=s[i]==s[j]?0:1;
                else if(s[i]!=s[j])
                {
                    dp[i][j]= 1 + min(dp[i+1][j],dp[i][j-1]);
                }
                else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            }
        }
        
        return dp[0][n-1];
        
    }
};