class Solution {
public:
    int minDifference(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //for(auto i:nums) cout<<i<<" ";cout<<endl;
        if(n<=3) return 0;
        int ans=INT_MAX;
        
        for(int i=0;i<=3;i++) 
        {
            int s=i;
            int e=n-1-3+i;
            //cout<<s<<"  "<<e<<" "<<nums[e]-nums[s]<<endl;
            ans=min(ans,nums[e]-nums[s]);
            
        }
        
        return ans;
    }
};