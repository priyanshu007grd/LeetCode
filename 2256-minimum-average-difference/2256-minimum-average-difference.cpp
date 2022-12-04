class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=INT_MAX;
        int idx=INT_MAX;
        
        vector<int> r(n+1,0);
        long long int sum=0;
        long long int count=0;
        
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            count++;
            
            r[i]=sum/count;
        }
        
        
        sum=0;
        count=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            count++;
            
            long long int avg = sum/count;
            long long int diff = llabs(avg-r[i+1]);
            
            if(diff<ans)
            {
                ans=diff;
                idx=i;
            }
        }
        
        return idx==INT_MAX?0:idx;
    }
};