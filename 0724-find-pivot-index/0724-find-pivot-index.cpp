class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<int> l(n,0);
        vector<int> r(n,0);
                
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) r[i]=nums[i]+r[i+1];
        
        l[0]=nums[0];
        if(l[0]==r[0]) return 0;
        for(int i=1;i<n;i++)
        {
            l[i]=nums[i]+l[i-1];
            if(l[i]==r[i]) return i;
        }
        
        return -1;
    }
};