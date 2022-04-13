class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        int xs=0,xe=n-1;
        int ys=0,ye=n-1;
        int c=1;
        
        while(xs<=xe && ys<=ye && c<=n*n)
        {
            for(int i=ys;i<=ye;i++) ans[xs][i]=c++;
            xs++;
            
            for(int i=xs;i<=xe;i++) ans[i][ye]=c++;
            ye--;
            
            if(xs<=xe)
            {
                for(int i=ye;i>=ys;i--) ans[xe][i]=c++;
                xe--;
            }
            
            if(ys<=ye)
            {
                for(int i=xe;i>=xs;i--) ans[i][ys]=c++;
                ys++;
            }
        }
        
        return ans;
        
    }
};