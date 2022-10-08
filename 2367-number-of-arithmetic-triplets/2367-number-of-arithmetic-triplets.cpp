class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        
        int cnt = 0;
        
        unordered_map<int,bool> mp;
        
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] = true;
        
        

        for(int i=0;i<nums.size();i++)
        {
            //Note Element are strictly increasing so for this case i<j<k is by default satisfly
            if(mp[nums[i]-diff] && mp[nums[i]+diff])
                cnt++;
        }
        
		
        return cnt;
    }
};