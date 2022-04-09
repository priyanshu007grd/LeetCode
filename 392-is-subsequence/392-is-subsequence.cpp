class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int a=s.size();
        int b=t.size();
        
        if(a>b) return false;
        
        int i,j;
        for( i=0,j=0;i<a && j<b;)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        return i==a;
    }
};