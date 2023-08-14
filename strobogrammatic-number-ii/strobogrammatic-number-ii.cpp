class Solution {
    map<char,int> m;
    vector<string> v;
    int n;
    int nn;
    string curr;
    vector<string> ans;
public:
    void bt() {
        if(curr.size()>=nn) {
            string rev="";
            for(int i=curr.size()-1;i>=0;i--) rev+=m[curr[i]];

            if(n%2==0) {
                ans.push_back(curr+rev);
            } else {
                ans.push_back(curr+ "0" + rev);
                ans.push_back(curr+ "1" + rev);
                ans.push_back(curr+ "8" + rev);
            }
            return;
        }

        for(int i=0;i<v.size();i++) {
            curr+=v[i];
            bt();
            curr.pop_back();
        }
    }
    vector<string> findStrobogrammatic(int n) {

        if(n==1) return {"0","1","8"};
        this->n=n;
        this->nn=n/2;
        ans.clear();
        m.clear();
        m['0']='0';
        m['1']='1';
        m['6']='9';
        m['8']='8';
        m['9']='6';
        v = {"0","1","6","8","9"};

        for(int i=1;i<v.size();i++) {
            curr+=v[i];
            bt();
            curr.pop_back();
        }

        return ans;
    }
};