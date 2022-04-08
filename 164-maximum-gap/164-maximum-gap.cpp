class Solution 
{
public:
    int maximumGap(vector<int>& nums) 
    {
        int n=nums.size();
        if (n < 2) return 0;
        
        auto lu=minmax_element(nums.begin(),nums.end());
        int l=*lu.first,u=*lu.second;
        
        int gap = max((u - l) / (n - 1), 1);
        int m = (u-l)/gap + 1;
        
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        
        for(auto num:nums)
        {
            int k = (num-l)/gap;
            bucketsMin[k]=min(bucketsMin[k],num);
            bucketsMax[k]=max(bucketsMax[k],num);
        }
        
        int i=0,j=0,ans=bucketsMax[0] - bucketsMin[0];
        
        while(i<m)
        {
            j=i+1;
            while(j<m && bucketsMin[j]==INT_MAX && bucketsMax[j]==INT_MIN) j++;
            
            if (j == m) break;
            ans=max(ans,bucketsMin[j]-bucketsMax[i]);
            i=j;
        }
        
        return ans;
    }
};