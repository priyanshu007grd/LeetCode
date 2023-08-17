class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        int ans=0;
        set<char> jewelSet;
        for(char jewel:jewels) jewelSet.insert(jewel);
        
        for(char stone:stones) {
            if(jewelSet.find(stone)!=jewelSet.end()) ans++;
        }
        
        return ans;     
    }
};