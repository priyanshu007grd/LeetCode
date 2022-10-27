class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n<2) return false;
        
        unordered_map<int,int> m;
        m[0]=-1;
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            int mod = k==0 ?sum:sum%k;
            if(m.find(mod)!=m.end())
            {
               if(i-m[mod]>1) 
                   return true;
            }
            else
            {
                m[mod]=i;
            }
        }
        
        return false;
    }
};