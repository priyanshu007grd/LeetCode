//https://leetcode.com/problems/stone-game-iii/discuss/574655/How-to-Approach-DP-problemsSolved-greater-Recursion-greater-Memoization-greater-DP
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> prefix(n + 1);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + stoneValue[i];
        }
        vector<int> dp(n + 4);
        for(int i = n; i > 0; i--){
            dp[i] = prefix[n] - prefix[i-1] - min(dp[i+1], min(dp[i+2], dp[i+3]));
        }
        if(dp[1]*2 > prefix[n]){
            return "Alice";
        }
        if(dp[1]*2 == prefix[n]){
            return "Tie";
        }
        return "Bob";
    }
};