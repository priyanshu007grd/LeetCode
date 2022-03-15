class Solution {
    public String minRemoveToMakeValid(String s) {
        int n=s.length();
        boolean[] f = new boolean[n];
        Arrays.fill(f,true);
        int count=0;
        for(int i=0;i<n;++i)
        {
            if(s.charAt(i)=='(') ++count;
            else if(s.charAt(i)==')'){
                if(count==0) f[i]=false;
                else --count;
            }
        }


        count=0;
        for(int i=n-1;i>=0;--i)
        {
            if(s.charAt(i)==')') ++count;
            else if(s.charAt(i)=='(')
            {
                if(count==0) f[i]=false;
                else --count;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;++i)
        {
            if(f[i]==true) sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}