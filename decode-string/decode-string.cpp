class Solution {
public:

    bool isdigit(char a) {return 0<=a-'0' && a-'0'<=9;}

    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};
/*
class Solution {
public:
    string decodeString(string s) 
    {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s) 
    {
        int num=0;
        string word = "";

        for(;pos<s.size(); pos++)
        {
            char cur = s[pos];

            if (cur >= '0' && cur <='9')
            {
                num = num*10 + cur - '0';
            } 
            else if(cur == '[') 
            {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } 
            else if(cur>='a' && cur<='z')
            {
                word += cur;
            }
            else if (cur == ']')
            {
                return word;
            } 
        }
        return word;
    }
};
*/