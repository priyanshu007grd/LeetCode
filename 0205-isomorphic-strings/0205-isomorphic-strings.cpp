class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        
        map<char,int> m1;
        map<char,int> m2;
        int count=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(m1.find(s[i])==m1.end() && m2.find(t[i])==m2.end())
            {
                m1[s[i]]=count;
                m2[t[i]]=count;
                count++;
            }
            else if(m1.find(s[i])!=m1.end() && m2.find(t[i])!=m2.end() && m1[s[i]]==m2[t[i]])
            {
                continue;
            }
            else
            {
                return false;
            }     
        }
        return true;
    }
};