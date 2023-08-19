struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>,vector<vector<int>>, cmp> pq;
        
        for(int i=0;i<points.size();i++) {
            int x=points[i][0];
            int y=points[i][1];
            int dis = y*y+x*x;
            
            pq.push({dis,x,y});
            
            if(pq.size()>k) pq.pop();
        }
        
        while(!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            cout<<t[0]<<endl;
            
            ans.push_back({t[1],t[2]});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
bool cmp(vector<int>& a,vector<int>& b) 
{ 
    return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]; 
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) 
    {
        nth_element(A.begin(),A.begin()+K,A.end(),cmp);
        return vector<vector<int>>(A.begin(), A.begin() + K);
    }
};
*/