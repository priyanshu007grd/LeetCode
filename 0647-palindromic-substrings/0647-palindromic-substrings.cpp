//https://www.interviewbit.com/problems/palindromic-substrings/
class Solution {
public:
    int count = 0;
    
    int countSubstrings(string s) 
    {
        if (s.size() == 0) return 0;
        
        for (int i = 0; i < s.size(); i++) 
        { 
            extendPalindrome(s, i, i); // odd length;
            extendPalindrome(s, i, i + 1); // even length
        }
        
        return count;
    }
    
    void extendPalindrome(string s, int left, int right) 
    {
        while (left >=0 && right < s.size() && s[left] == s[right]) 
        {
            count++; left--; right++;
        }
    }
};

/*
int Solution::solve(string A) 
{
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int ans = 0;
    
    for(int l=0;l<n;l++)
    {
        for(int i=0;i<n-l;i++)
        {    
            int j=i+l;
            if(i == j) dp[i][j] = 1;
            else if(i+1 == j) dp[i][j] = A[i]==A[j]?1:0;
            else dp[i][j] = (dp[i+1][j-1]==1 && A[i]==A[j])?1:0;
            if(dp[i][j]) ++ans;
        }
    }
    return ans;
}
*/