class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n=secret.size();
        map<char,int> m;
        vector<bool> vis(n,false);
        int bull=0;
        int cow=0;
        
        for(int i=0;i<n;i++) {
            
            if(secret[i]==guess[i]) {
                bull++;
                vis[i]=true;
            }
            else m[secret[i]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(vis[i]==false) {
                if(m[guess[i]]-- >0) cow++;
            }
        }
        
        
        return to_string(bull)+"A"+to_string(cow)+"B";
        
    }
};