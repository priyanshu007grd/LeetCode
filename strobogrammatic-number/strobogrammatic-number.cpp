class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char,char> m;
        m['0']='0';
        m['1']='1';
        m['6']='9';
        m['8']='8';
        m['9']='6';

        int l=0;
        int r=num.size()-1;

        

        while(l<=r) {
            cout<<l<<"  "<<r<<endl;
            cout<<(num[l])<<" "<<(num[r])<<endl;

            if(num[l]!='0' && num[l]!='1' && num[l]!='6' && num[l]!='8' && num[l]!='9') return false;
            if(num[r]!='0' && num[r]!='1' && num[r]!='6' && num[r]!='8' && num[r]!='9') return false;
            
            if(l==r && (num[l]=='6' || num[l]=='9')) return false;

            if(m[num[l]]!=num[r]) return false;
           
            l++;
            r--; 
        }
        return true;
    }
};