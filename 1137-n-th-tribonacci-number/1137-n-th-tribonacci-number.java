class Solution {
    public int tribonacci(int n) {
        
        if(n==0) return 0;
        if(n<=2) return 1;
        int a=0;
        int b=1;
        int c=1;
        
        int ans=0;
        for(int i=2;i<n;i++) {
            ans=a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        
        return ans;   
    }
}