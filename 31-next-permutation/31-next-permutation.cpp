class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        for(i = nums.size() - 2 ; i >= 0 ; i--)
        {
            if(nums[i] < nums[i+1]) break;
        }

        sort(nums.begin() + i + 1,nums.end());

        for(int j = i; j < nums.size();j++ )
        {
            if(nums[j] > nums[i])
            {
                swap(nums[i] , nums[j]);
                break;
            }
        }
    }
};