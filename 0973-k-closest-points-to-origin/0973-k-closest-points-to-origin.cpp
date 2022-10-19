bool cmp(vector<int>& a,vector<int>& b) 
{ 
    return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]; 
}
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) 
    {
        nth_element(A.begin(),A.begin()+K,A.end(),cmp);
        return vector<vector<int>>(A.begin(), A.begin() + K);
    }
};