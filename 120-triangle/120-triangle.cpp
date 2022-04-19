class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) 
    {
        int m=a.size();
        if(m==0) return 0;
        if(m==1) return a[0][0];
        int ans=INT_MAX;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(j==0) a[i][j]+=a[i-1][j];
                else if(i==j) a[i][j]+=a[i-1][j-1];
                else a[i][j]+=min(a[i-1][j],a[i-1][j-1]);

                if(i==m-1 && a[i][j]<ans)
                {
                    ans=a[i][j];
                    //cout<<ans<<endl;
                }
            }
        }

        //print(a);
        return ans;
        
    }
};