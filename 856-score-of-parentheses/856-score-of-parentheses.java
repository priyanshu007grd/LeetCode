class Solution {
    public int scoreOfParentheses(String s) {

        Stack<Integer> st = new Stack();
        Integer score=0;
        for(Character c:s.toCharArray())
        {
            if(c=='(')
            {
                st.push(score);
                score=0;
            }
            else
            {
                score =st.peek()+Integer.max(2*score,1);
                st.pop();
            }
        }

        return score;
    }
}