class Solution {
public:
    bool isPredecessor(string a, string b)
    {
       int i = 0, j = 0, n = a.size(), m = b.size(), mismatch = 0;
        if(m - n != 1)  return false;
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                mismatch++;
                j++;
            }
            if(mismatch > 1)    return false;
        }
        return true;
    }
    static bool cmp(string a,string b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) 
    {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        //for(auto i:words) cout<<i<<"    ";cout<<endl;
        int ans=1;
        vector<int> lis(n,1);
        
        for(int j=1;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(isPredecessor(words[i],words[j]))
                {
                    //cout<<i<<"  "<<j<<endl;
                    lis[j]=max(lis[j],lis[i]+1);
                }
            }
            ans=max(ans,lis[j]);
        }
        
        return ans;
    }
};