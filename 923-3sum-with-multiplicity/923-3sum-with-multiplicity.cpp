class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        int ans=0;
        int n=arr.size();
        unordered_map<int,int> m;
        
        for(int j=0;j<n;j++)
        {
            ans = (ans+m[target-arr[j]])%1000000007;
            for(int i=0;i<j;i++)
            {
                //int key = arr[i]+arr[j];
                m[arr[i]+arr[j]]++;
            }
        }
        
        return ans;
    }
};