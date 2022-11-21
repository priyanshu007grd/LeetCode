class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        
        int n=maze.size();
        int m=maze[0].size();
        
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<vector<int>> q;
        
        int x=entrance[0];
        int y=entrance[1];
        int step=0;
        
        q.push({x,y});
        vis[x][y]=1;
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                auto t=q.front();
                q.pop();
                x=t[0];
                y=t[1];
                
                for(auto dir:dirs)
                {
                    int xx=x+dir[0];
                    int yy=y+dir[1];
                    

                    if(xx>=0 && xx<n && yy>=0 && yy<m)
                    {
                        if(vis[xx][yy]==0 && maze[xx][yy]=='.')
                        {
                            q.push({xx,yy});
                            vis[xx][yy]=1;
                        }
                    }
                    else
                    {
                        if(step>0) return step;
                    }
                }
                
            }
            step++;
        }
        return -1;
    }
};