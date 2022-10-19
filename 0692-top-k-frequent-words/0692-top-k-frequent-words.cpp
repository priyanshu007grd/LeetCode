struct cmp {
	bool operator()(pair<string,int> const& p1, pair<string,int> const& p2) 
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
	}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> freq;
        for(auto word:words)
        {
            freq[word]++;
        }
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> pq;
        
        for(auto p:freq)
        {
            pq.push({p.first,p.second});
            if(pq.size()>k) pq.pop();
        }
        
        
        vector<string> output;
        while(!pq.empty()){
            output.insert(output.begin(), pq.top().first);
            pq.pop();
        }
        return output;
    }
};