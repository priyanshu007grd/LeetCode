// similar question : https://www.interviewbit.com/problems/arrange-ii/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int D) 
    {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(D,vector<int>(n,INT_MAX));
        
        int currMax=INT_MIN;
        for(int i=0;i<n;i++)
        {
            currMax=max(currMax,jobDifficulty[i]);
            dp[0][i]=currMax;
        }
        
        
        for(int d=1;d<D;d++)
        {
            for(int i=1;i<n;i++)
            {
                currMax=INT_MIN;
                for(int j=i;j>0;j--)
                {
                    currMax=max(currMax,jobDifficulty[j]);
                    
                    if(dp[d-1][j-1]!=INT_MAX)
                        dp[d][i]=min(dp[d][i],currMax+dp[d-1][j-1]);
                }
            }
        }
        
        return dp[D-1][n-1]==INT_MAX?-1:dp[D-1][n-1];
        
    }
};