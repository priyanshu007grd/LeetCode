class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& A) 
        {
            int n=A.size();
            if(n<3) return 0;
            
            int res = 0;
            unordered_map<long, int> m[A.size()];
            
            for (int i = 0; i < A.size(); ++i)
            {
                for (int j = 0; j < i; ++j) 
                {
                    long diff = (long)A[i]-(long)A[j];
                    auto it = m[j].find(diff);
                    int cnt = it == m[j].end() ? 0 : it->second;
                    m[i][(long)A[i] - A[j]] += cnt + 1;
                    
                    res += cnt;  // cnt+1 also include series of length 2
                }
            }

            return res;
        }
};