class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        
            int m=A.size(),n,j,i,ans=0,k,l;
    if(m!=0)
     n=A[0].size();
    else
    return 0;
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0&&j==0)
            {
            continue;
            }
            if(i==0)
            A[0][j]+=A[0][j-1];
            else if(j==0)
            A[i][0]+=A[i-1][0];
            
            else
            A[i][j]+=A[i][j-1]+A[i-1][j]-A[i-1][j-1];
            
           
        }
    }
    
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=i;k<m;k++)
            {
                
                for(l=j;l<n;l++)
                {
                  int  sub=A[k][l];
                    if(i>0)
                    sub-=A[i-1][l];
                    if(j>0)
                    sub-=A[k][j-1];
                    if(i>0&&j>0)
                    sub+=A[i-1][j-1];
                    
                    
                    if(sub==target)
                    {
                       
                    ans++;
                    }
                }
            }
            
        }
    }
    
 return ans;  
        
    }
};