class Solution {
public:
    int countTexts(string pressedKeys) {
        
        int mod=1000000007;
        int n=pressedKeys.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++) {
            
            dp[i]=dp[i-1];
            int flag=0;
            if(i-2>=0 && pressedKeys[i-1]==pressedKeys[i-2]) {
                dp[i]= (dp[i] + dp[i-2])%mod;
                flag++;
            }
            
            if(flag>0 && i-3>=0 && pressedKeys[i-1]==pressedKeys[i-3]) {
                dp[i]= (dp[i] + dp[i-3])%mod;
                flag++;
            }
            
            if(flag>1 && i-4>=0 && (pressedKeys[i-1]=='7' || pressedKeys[i-1]=='9')  && pressedKeys[i-1]==pressedKeys[i-4]) {
                dp[i]= (dp[i] + dp[i-4])%mod;
            }
            
        }
        
        return dp[n];
    }
};

/**
2 2 2 3 3

2
*/