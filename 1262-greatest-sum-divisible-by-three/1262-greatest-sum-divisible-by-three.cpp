class Solution {
public:
    int maxSumDivThree(vector<int>& A) {
        vector<int> pre(3,0);
        vector<int> curr(3,0);
        for (int a : A)
        {
            //cout<<a<<endl;
            //for(auto i:dp) cout<<i<<"   ";cout<<endl;
            for (auto i : pre)
            {
                curr[(i + a) % 3] = max(curr[(i + a) % 3], i + a); 
            }
            pre=curr;
            //for(auto i:dp) cout<<i<<"   ";cout<<endl;
            //cout<<endl;
        }

        return curr[0];
    }
};