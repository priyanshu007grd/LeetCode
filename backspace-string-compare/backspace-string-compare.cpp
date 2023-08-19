class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> s1;
        stack<char> s2;
        
        for(auto c:s)
        {
            if(c=='#' && !s1.empty()) s1.pop();
            else if(c!='#') s1.push(c);
        }
        
        for(auto c:t)
        {
            if(c=='#' && !s2.empty()) s2.pop();
            else if(c!='#') s2.push(c);
        }
        
        while(!s1.empty() && !s2.empty())
        {
            if(s1.top()!=s2.top()) return false;
            s2.pop();
            s1.pop();
        }
        
        return s1.empty() && s2.empty();
        
    }
};