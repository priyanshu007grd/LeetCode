class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int n=pushed.length;
        Stack<Integer> s = new Stack<Integer>();

        int p=0;
        for(int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.peek()==popped[p] )
            {
                s.pop();
                p++;
            }
        }

        return s.empty();
    }
}