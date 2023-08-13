class Solution {
    map<string,map<string,double>> g;
    vector<double> ans;
    double fAns;
    set<string> vis;
public:
    void createAdjList(vector<vector<string>>& equations, vector<double>& values) {
        for(int i=0;i<equations.size();i++) {
            string a=equations[i][0];
            string b=equations[i][1];
            double c=values[i];

            g[a][b]=c;
            g[b][a]=1/c;
        }
    }

    void dfs(string start,string end, double curr) {
        if(g.find(start)==g.end()) return;

        if(start==end) {
            fAns=curr;
            return;
        }


        for(auto gg:g[start]) {
            string next=gg.first;
            double value=gg.second;

            if(vis.find(next)==vis.end()) {
                vis.insert(next);
                dfs(next,end,curr*value);
            }
           

            if(fAns!=-1) return;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        g.clear();
        createAdjList(equations,values);


        for(int i=0;i<queries.size();i++) {
            fAns=-1.0;
            vis.clear();
            
            string start=queries[i][0];
            string end=queries[i][1];

            vis.insert(start);
            dfs(start,end,1.0);
            ans.push_back(fAns);
        }

        
        return ans;
    }
};