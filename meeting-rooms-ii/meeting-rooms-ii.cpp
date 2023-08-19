class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) 
    {
        map<int,int> m;
        int ans=0;
        int curr=0;
        
        for(auto i: A) 
        {
            m[i[0]]++;
            m[i[1]]--;
        }
        
        
        for(auto i:m)
        {
            curr+=i.second;
            ans=max(ans,curr);
        }
        
        return ans;
        
    }
};
/*
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& A) 
    {
        vector<pair<int,int>> v;
        int ans=0;
        int curr=0;
        
        for(auto i: A) 
        {
            v.push_back({i[0],1});
            v.push_back({i[1],-1});
        }
        
        sort(v.begin(),v.end());
        
        for(auto i:v)
        {
            curr+=i.second;
            ans=max(ans,curr);
        }
        
        return ans;
        
    }
};
*/


/*
struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};
int Solution::solve(vector<vector<int> > &A) 
{
    sort(A.begin(),A.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> q;
    int ans=0;
    
    for(int i=0;i<A.size();i++)
    {
        //cout<<A[i][0]<<endl;
        while(!q.empty() && q.top().second<=A[i][0]) 
        {
            //cout<<q.top().first<<"  ";
            q.pop();
        }
        //cout<<endl;
 
        q.push({A[i][0],A[i][1]});
        int size=q.size();
        ans=max(ans,size);
    }
    return ans;
}
*/