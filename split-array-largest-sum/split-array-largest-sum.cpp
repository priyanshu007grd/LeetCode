class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int m)
    {
        int sum=0;
        for(auto i:nums)
        {
            if(sum+i<m)
                sum+=i;
            else if(sum+i==m)
            {
                k--;
                sum=0;
            }
            else
            {
                k--;
                sum=i;
            }

        }
        if(sum) k--;

        return k>=0;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int ans=INT_MAX;

        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);

        while(l<=h)
        {
            int m=(l+h)/2;
            if(isPossible(nums,k,m))
            {
                h=m-1;
                ans=min(ans,m);
            }
            else
            {
                l=m+1;
            }
                
        }
        return ans;
        
    }
};