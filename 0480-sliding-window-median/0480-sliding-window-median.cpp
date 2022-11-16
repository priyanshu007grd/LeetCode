class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> median;
        
        multiset<int> window;
        
        int mid=k/2;
        
        for(int i=0;i<nums.size();i++)
        {
            window.insert(nums[i]);

            if(i+1>=k)
            {
                auto mid = next(window.begin(), k / 2);
                median.push_back( ( double(*mid) + *prev(mid, 1 - k%2)) / 2);
                window.erase(window.lower_bound(nums[i+1-k]));
            }
        }
        
        return median;
    }
};