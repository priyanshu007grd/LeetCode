class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i=0; i<n*m; i++)
        {
            int temp=(i+k)%(n*m);
            int x=i/n;
            int y=i%n;
            
            int newX=temp/n;
            int newY=temp%n;
            
           ans[newX][newY]=grid[x][y];
        }
        return ans;
    }
};