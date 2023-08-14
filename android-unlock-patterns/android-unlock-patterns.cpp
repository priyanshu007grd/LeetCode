class Solution {
    map<int,map<int,int>> m;
    vector<int> vis;
    string curr="";
    int s,e;
    int ans=0;
    set<string> sets;
public:
    void bt(int start) {
        if(start==e) {
            if(curr.size()>=s && curr.size()<=e && sets.find(curr)==sets.end()) {
                sets.insert(curr);
                ans++;
            } 
            return;
        }

        if(start>=s) {
            if(curr.size()>=s && curr.size()<=e && sets.find(curr)==sets.end()) {
                sets.insert(curr);
                ans++;
            } 
        }

        for(int i=1;i<=9;i++) {

            if(vis[i]==0) {

                if(curr.size()==0) {
                    curr+=to_string(i);
                    vis[i]=1;
                    bt(start+1);
                    vis[i]=0;
                    curr.pop_back();
                } else {
                    int a=curr.back()-'0';
                    int b=i;

                    if(m.find(a)==m.end() || m[a].find(b)==m[a].end() || vis[m[a][b]]==1) {
                        curr+=to_string(i);
                        vis[i]=1;
                        bt(start+1);
                        vis[i]=0;
                        curr.pop_back();
                    }

                    // else if(m.find(a)!=m.end() && m[a].find(b)!=m[a].end() && vis[m[a][b]]==1) {

                    //     curr+=to_string(i);
                    //     vis[i]=1;
                    //     bt(start+1);
                    //     vis[i]=0;
                    //     curr.pop_back();
                    // }
                }

            }
        }
    }
    int numberOfPatterns(int s, int e) {

        m[1][3] = 2;
        m[1][9] = 5;
        m[1][7] = 4;
        

        m[3][9] = 6;
        m[3][7] = 5;
        m[3][1] = 2;
        
        m[9][7] = 8;
        m[9][1] = 5;
        m[9][3] = 6;

        m[7][1] = 4;
        m[7][3] = 5;
        m[7][9] = 8;

        m[2][8] = m[8][2] = 5;
        m[4][6] = m[6][4] = 5;
        vis.assign(10,0);
        curr="";
        this->s=s;
        this->e=e;
        sets.clear();

        bt(0);

        return ans;
    }
};