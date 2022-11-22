class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            int squares = INT_MAX;
            
            for (int j=1; j*j<=i; ++j)
                squares = min(squares, dp[i-j*j] + 1);
            
            dp[i] = squares;
        }
        
        //for(int i=0;i<=n;i++) cout<<dp[i]<<"    ";cout<<endl;
        return dp[n];
    }
};