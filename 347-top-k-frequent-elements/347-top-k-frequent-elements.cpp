/*
If we have stream of integer

map<int,int> m; //element -> frequency
map<int,set<int>> // frequency - > set of element having frequency

every time frequency of element increases remove from previous frequency set and add to new frequency set

*/
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        map<int,int> m;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        
        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }
        
        while(k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};