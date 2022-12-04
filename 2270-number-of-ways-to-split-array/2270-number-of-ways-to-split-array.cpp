class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        
        vector<long long int> r(n,0);
        long long int sum=0;

        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            r[i]=sum;
        }
        
        
        sum=0;
        for(int i=0;i<n-1;i++)
        {
            sum+=nums[i];
            
            if(sum>=r[i+1])
            {
                count++;
            }
        }
        
        return count;
        
    }
};