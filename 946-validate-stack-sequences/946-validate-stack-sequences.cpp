class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=pushed.size();
        stack<int> s;
        
        int p=0;
        for(int i=0;i<n;i++) 
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[p] )
            {
                s.pop();
                p++;
            }
        }
        
        return s.empty();
        
    }
};