class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<int> lis(n,1);
        vector<int> child(n,-1);
        int idx=0;
        int maxV=INT_MIN;
        
        for(int j=1;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(nums[j]%nums[i]==0 && lis[i]+1>=lis[j])
                {
                    lis[j]=lis[i]+1;
                    child[j] = i;
                }
                
                if(lis[j]>maxV)
                {
                    maxV=lis[j];
                    idx=j;
                }
            }
        }
        
        while(idx!=-1)
        {
            ans.push_back(nums[idx]);
            idx=child[idx];
        }
        
        return ans;
        
    }
};