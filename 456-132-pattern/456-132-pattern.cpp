class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        /*
        int n=nums.size();
        if(n<3)
            return false;
        
        vector<int> r(n,0);
        r[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
            r[i]=min(r[i+1],nums[i]);
        
        int l=nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(l<r[i+1] && r[i+1]<nums[i])
                return true;
            
            l=min(l,nums[i]);
        }
        
        return false;
        */
        int s3 = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < s3 ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              s3 = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
        
    }
};
