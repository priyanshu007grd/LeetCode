class Solution {
public:
    int numDistinct(string a, string b) 
    {
        int m=a.size();
        int n=b.size();
        if(n==0) return 1;
        if(m==0) return 0;

        unsigned long int dp[m+1][n+1];


        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;

                else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }


        return dp[m][n];
    }
};