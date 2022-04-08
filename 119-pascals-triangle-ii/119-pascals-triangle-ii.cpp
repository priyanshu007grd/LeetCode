class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        int line=rowIndex+1;
        unsigned long int c=1;
        vector<int> ans;
        ans.push_back(c);
        
        for(int i=1;i<line;i++)
        {
            c=c*(line-i)/i;
            ans.push_back(c);
        }
        
        return ans;
        
    }
};