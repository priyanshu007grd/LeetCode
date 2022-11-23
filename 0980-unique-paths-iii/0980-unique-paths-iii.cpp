class Solution {
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
public:
    void bt(vector<vector<int>>& grid,vector<vector<int>>& vis,int &e,int &res,int step,int x, int y,int n, int m)
    {                
        if(grid[x][y]==2)
        {
            if(step==e) res++;
            return;
        }
        
        
        for(int i=0;i<dir.size();i++)
        {
            int xx=x+dir[i][0];
            int yy=y+dir[i][1];

            if(xx>=0 && xx<n && yy>=0 && yy<m && (grid[xx][yy]==0 || grid[xx][yy]==2) && vis[xx][yy]==0)
            {
                vis[xx][yy]=1;
                bt(grid,vis,e,res,step+1,xx,yy,n,m);
                vis[xx][yy]=0;

            }
        }        
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        int step=-1;
        int ii,jj;
        int e=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ii=i;
                    jj=j;
                }
                else if(grid[i][j]==0)
                {
                    e++;
                }
            }
        }
        
        bt(grid,vis,e,res,step,ii,jj,n,m);
        
        return res;
    }
};