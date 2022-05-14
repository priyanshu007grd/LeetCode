class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<vector<pair<int,int>>> g(N+1);
        
        for(int i=0;i<times.size();i++)
        {
            g[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dist(N+1,INT_MAX);
        vector<int> vis(N+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,K});
        dist[K]=0;
        vis[K]=1;
        
        while(!q.empty())
        {

            int w1=q.top().first;
            int n1=q.top().second;
            q.pop();
            
            for(int j=0;j<g[n1].size();j++)
            {
                int n2=g[n1][j].first;
                int w2=g[n1][j].second;

                if( w2!=INT_MAX && dist[n1]+w2<dist[n2])
                {
                    dist[n2]=dist[n1]+w2;
                    q.push({dist[n2],n2});
                }
            }
            
            cout<<n1<<endl;
            for(int k=1;k<=N;k++) cout<<k<<"="<<dist[k]<<"     ";cout<<endl;
        }
        
        int ans=0;
        for(int i=1;i<=N;i++) ans=max(ans,dist[i]);
        return ans==INT_MAX?-1:ans;
    }
};