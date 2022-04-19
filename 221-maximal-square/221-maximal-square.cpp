class Solution {
public:
    int largestRectangleArea(vector<int> &A) 
    {
        int n=A.size();
        vector<int> prevSmaller(n,-1);
        vector<int> nxtSmaller(n,-1);

        stack<pair<int,int>> s1;
        for(int i=n-1;i>=0;i--)
        {
            if(s1.empty() || A[i]>=s1.top().first) s1.push(make_pair(A[i],i));
            else
            {
                while(!s1.empty() && A[i]<s1.top().first)
                {
                    pair<int,int> p=s1.top();
                    s1.pop();
                    prevSmaller[p.second] = i;
                }

                s1.push(make_pair(A[i],i));
            }
        }

        stack<pair<int,int>> s2;
        for(int i=0;i<n;i++)
        {
            if(s2.empty() || A[i]>=s2.top().first) s2.push(make_pair(A[i],i));
            else
            {
                while(!s2.empty() && A[i]<s2.top().first)
                {
                    pair<int,int> p=s2.top();
                    s2.pop();
                    nxtSmaller[p.second] = i;
                }
                s2.push(make_pair(A[i],i));
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l= prevSmaller[i];
            int r= nxtSmaller[i]==-1?n:nxtSmaller[i];
            //cout<<l<<"  "<<r<<endl;
            int area = min(A[i],(r-l-1))*min(A[i],(r-l-1));
            ans = max(ans,area);
        }
        return ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        
        int m=matrix[0].size();
        int n=matrix.size();
        vector<vector<int>> A(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]=matrix[i][j]-'0';
            }
        }
        int ans=largestRectangleArea(A[0]);

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j]=A[i][j]*(A[i-1][j]+1);
            }
            ans=max(ans,largestRectangleArea(A[i]));
        }
        return ans; 
    }
};