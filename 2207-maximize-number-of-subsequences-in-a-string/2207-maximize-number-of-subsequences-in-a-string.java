//https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/discuss/1863900/JavaC%2B%2BPython-Straight-Forward-Solution
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {

        //int n=text.length();
        long c1=0,c2=0,ans=0,max=0;

        for(Character c:text.toCharArray()) {

            if(c==pattern.charAt(1)) {
                ans+=c1;
                c2++;
            }
            if(c==pattern.charAt(0)) c1++;
        }
        
        return ans + Math.max(c1,c2); 
    }
}