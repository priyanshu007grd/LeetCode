class Solution {
public:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int ii, int jj)
    {
        int ans=0;
        int r=img1.size();
        int c=img1[0].size();
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if( (i+ii<0 || i+ii>=r) ||  (j+jj<0 || j+jj>=c))
                    continue;
                
                if(img1[i][j]==1 && img2[i+ii][j+jj]==1) ans++;
            }
        }
        
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int ans=0;
        int r=img1.size();
        int c=img1[0].size();
        for(int i=-r;i<r;i++)
        {
            for(int j=-c;j<c;j++)
            {
                ans=max(ans,overlap(img1,img2,i,j));
            }
        }
        
        return ans;
    }
};