class Solution {
public:
    int minCost(int A, vector<int>& B) 
    {
        vector<int> p;
        p.push_back(0);
        for (int b: B) p.push_back(b);
        p.push_back(A);
        sort(p.begin(), p.end());

        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                //cout<<i<<" "<<i+l-1<<endl;
                dp[i][i+l-1] = INT_MAX;
                for (int k = i + 1; k < i + l - 1; k++)
                {
                    //cout<<i<<"  "<<k<<" "<<i+l-1<<endl;
                    //cout<<dp[i][i+l-1]<<" "<<dp[i][k]<<"    "<<dp[k][i+l-1]<<endl;
                    //cout<<endl;
                    dp[i][i+l-1] = min(dp[i][i+l-1], dp[i][k] + dp[k][i+l-1] + p[i+l-1] - p[i]);
                    //cout<<dp[i][i+l-1]<<" "<<dp[i][k]<<"    "<<dp[k][i+l-1]<<endl;
                }
                    
            }

        }
        
        return dp[0][n-1];
        
    }
};