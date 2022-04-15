class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 1, max_len = 1;
        vector<pair<int,int>> dp(n,{1,1});
        
        
        for(int j = 1; j<n; j++)
        {
            for(int i = 0; i<j ; i++)
            {
                if(nums[i] < nums[j])
                {
                    if(dp[j].first == dp[i].first + 1)dp[j].second += dp[i].second;
                    if(dp[j].first < dp[i].first + 1)dp[j] = {dp[i].first + 1, dp[i].second};
                }
            }
            if(max_len == dp[j].first) res += dp[j].second;
            if(max_len < dp[j].first){
                max_len = dp[j].first;
                res = dp[j].second;
            }
        }
        return res;
    }
};