// solution : https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C%2B%2B-DP-solution-with-short-explanation
class Solution {
public: 
    int nthUglyNumber(int n) 
    {
        vector<int> dp(n);
        dp[0]=1;
        int l1=0,l2=0,l3=0;
        
        for(int i=1;i<n;i++)
        {
            int t = min(2*dp[l1],min(3*dp[l2],5*dp[l3]));
            dp[i]=t;
            
            if(t==2*dp[l1]) l1++;
            if(t==3*dp[l2]) l2++;
            if(t==5*dp[l3]) l3++;
        }
        
        return dp[n-1];
    }
};
/*
class Solution {
public: 
    int nthUglyNumber(int n) 
    {
        if(n<2) return 1;
        n--;
        
        vector<int> v{2,3,5};
        
        set<unsigned long long int> s;
        priority_queue<unsigned long long int,vector<unsigned long long int>,greater<unsigned long long int>> pq;
        
        pq.push(2);s.insert(2);
        pq.push(3);s.insert(3);
        pq.push(5);s.insert(5);
        
        while(--n)
        {
            unsigned long long int t=pq.top();
            pq.pop();
            for(int i=0;i<v.size();i++)
            {
                unsigned long long int t1=v[i]*t;
                
                if(s.find(t1)==s.end())
                {
                    pq.push(v[i]*t);
                    s.insert(t1);
                }
                
            }
            //cout<<t<<endl;
        }
        return pq.top();
    }
};
*/