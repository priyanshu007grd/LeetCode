class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) 
        {
            if (prices[i-1] < prices[i])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};

/*
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] dp = new int[n];
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1] + Math.max(0,prices[i]-prices[i-1]);
        }
        return dp[n-1];
    }
}
*/