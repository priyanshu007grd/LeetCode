class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<int> leftSum(n,0);
        vector<int> rightSum(n,0);
                
        rightSum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) rightSum[i]=nums[i]+rightSum[i+1];
        
        leftSum[0]=nums[0];
        if(leftSum[0]==rightSum[0]) return 0;
        for(int i=1;i<n;i++)
        {
            leftSum[i]=nums[i]+leftSum[i-1];
            if(leftSum[i]==rightSum[i]) return i;
        }
        
        
        return -1;
    }
};