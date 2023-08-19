//approch 1
/*
int Solution::trap(const vector<int> &A) 
{
    int n=A.size();
    if(n<3) return 0;
    int max_val=INT_MIN;
    int max_i=-1;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]>max_val)
        {
            max_val=A[i];
            max_i=i;
        }
    }
    
    int max_s=A[0],max_e=A[n-1];
    int sum=0;
    
    for(int i=0;i<max_i;i++) 
    {
        max_s=max(max_s,A[i]);
        sum=sum + max(0,max_s-A[i]);
    }
    for(int i=n-1;i>max_i;i--) 
    {
        max_e=max(max_e,A[i]);
        sum=sum + max(0,max_e-A[i]);
    }
    
    return sum;
}
*/
class Solution {
public:
    int trap(vector<int>& A) 
    {

        int n=A.size();
    
        int l_max=A[0];
        int r_max=A[n-1];
        int i=0,j=n-1;
        int result=0;
        
        while(i<j)
        {
            if(A[i]<A[j])
            {
                l_max=max(l_max,A[i]);
                result+=l_max-A[i];
                i++;
            }
            else
            {
                r_max=max(r_max,A[j]);
                result+=r_max-A[j];   
                j--;
                
            }
        }
        return result;
        
    }
};