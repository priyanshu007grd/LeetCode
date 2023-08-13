class Solution {
public:
    int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    vector<vector<int> > dp; // dp[i][j] will store maximum path length starting from matrix[i][j]
    int maxPath, n, m;
    vector<vector<int>> matrix;
    
    int solve(int i, int j)
    {
        if(dp[i][j]) return dp[i][j];
        dp[i][j] = 1;

        for(int k = 0; k < 4; k++)
        { 
            int ii = i + dir[k][0], jj = j + dir[k][1];
            
            if(ii < 0 || jj < 0 || ii >= n || jj >= m || matrix[ii][jj] <= matrix[i][j]) continue;
            dp[i][j] = max(dp[i][j], 1 + solve(ii, jj));
        }
        
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        this->matrix=matrix;
        maxPath = 0, n = size(matrix), m = size(matrix[0]);
        dp.resize(n, vector<int>(m));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxPath = max(maxPath, solve(i, j)); 
        
        return maxPath;
    }
};