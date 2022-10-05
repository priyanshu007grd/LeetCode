class Solution {
public:
    #define MOD 1000000007
    
    int numRollsToTarget(int N, int K, int target) {
        
        vector<vector<int>> dp(N+1,vector<int>(target+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=target;j++) {
                
                for(int k=1;k<=K;k++) {
                    if(j-k>=0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k])%MOD;
                    }
                }
            }
        }
        
        return dp[N][target];
        
    }
};