/*
Connected stones can be reduced to 1 stone,
the maximum stones can be removed = stones number - islands number.
so just count the number of "islands".
*/
class Solution {
    vector<vector<int>> stones;
    map<int,set<int>> xMap;
    map<int,set<int>> yMap;
    vector<int> vis;
    int n;
public:
    void dfs(int u) {
        
        int x=stones[u][0];
        int y=stones[u][1];
        for(int v:xMap[x]) {
            if(vis[v]==0) {
                vis[v]=1;
                dfs(v);
            }
        }

        for(int v:yMap[y]) {
            if(vis[v]==0) {
                vis[v]=1;
                dfs(v);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        this->stones=stones;
        this->n=stones.size();
        vis.assign(n,0);

        for(int i=0;i<n;i++) {
            int x=stones[i][0];
            int y=stones[i][1];
            
            xMap[x].insert(i);
            yMap[y].insert(i);
        }

        int count=0;
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                vis[i]=1;
                dfs(i);
                count++;         
            }   
        }

        return n-count;
    }
};