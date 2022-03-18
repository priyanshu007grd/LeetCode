class Solution {
    public String removeDuplicateLetters(String s) {

        StringBuilder ans = new StringBuilder();
        Stack<Character> st = new Stack<>();
        Map<Character,Integer> f = new HashMap<>();
        for(Character c:s.toCharArray()) f.put(c,f.getOrDefault(c,0)+1);
        boolean[] vis = new boolean[26];  // default value is false

//        Boolean[] vis = new Boolean[26];
//        Arrays.fill(vis,false);

        for(Character c:s.toCharArray()) {

            if(vis[c-'a']==false) {

                while(!st.isEmpty() && st.peek()>c && f.get(st.peek())>0) {
                    vis[st.peek()-'a'] = false;
                    st.pop();
                }
                vis[c-'a']=true;
                st.push(c);
            }
            f.put(c,f.getOrDefault(c,1)-1);
        }
        
        while(!st.isEmpty()) {
            ans.insert(0,st.pop());
        }
        
        return ans.toString();
    }
}