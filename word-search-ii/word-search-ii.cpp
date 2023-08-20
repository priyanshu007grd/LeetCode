class TrieNode {
public:
    string word="";
    unordered_map<char,TrieNode*> m;
};

class Solution {
    TrieNode* trie;
    vector<vector<char>> board;
    vector<string> words;
    vector<vector<int>> vis;
    vector<vector<int>> dir;
    vector<string> ans;
    int m,n;
    
public:
    void buildTrie() {
        trie=new TrieNode();
        
        for(int i=0;i<words.size();i++) {
            TrieNode* temp=trie;
            for(int j=0;j<words[i].size();j++) {
                char c=words[i][j];
                if(temp->m.find(c)==temp->m.end()) {
                    temp->m[c]=new TrieNode();
                    temp=temp->m[c];
                } else {
                    temp=temp->m[c];
                }
            }
            temp->word=words[i];
        }
    }


    void bt(int x,int y, TrieNode* temp) {

        if(temp->word!="") {
            ans.push_back(temp->word);
            temp->word="";
        } 
        
        for(int i=0;i<4;i++) {
            int xx=x+dir[i][0];
            int yy=y+dir[i][1];

           
            if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0) {
                int c=board[xx][yy];
                
                if(temp->m.find(c)!=temp->m.end()) {
                    vis[xx][yy]=1;
                    bt(xx,yy,temp->m[c]);
                    vis[xx][yy]=0;
                }
                
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->n=board.size();
        this->m=board[0].size();

        this->board=board;
        this->words=words;

        this->dir={{1,0},{-1,0},{0,1},{0,-1}};
        this->ans.clear();

        vis.assign(n,vector<int>(m,0));

        buildTrie();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                TrieNode* temp=trie;
                char c=board[i][j];
               
                if(trie->m.find(c)!=trie->m.end()) {
                    vis[i][j]=1;
                    bt(i,j,trie->m[c]);
                    vis[i][j]=0;
                } 

            }
        }

        return  ans;   
    }
};
/*
// Approch 1: TLE (intutive)
class TrieNode {
public:
    bool isTerminal;
    unordered_map<char,TrieNode*> m;
};

class Solution {
    TrieNode* trie;
    vector<vector<char>> board;
    vector<string> words;
    vector<vector<int>> vis;
    vector<vector<int>> dir;
    vector<string> ans;
    string curr;
    unordered_set<string> s;
    int m,n;
    
public:
    void buildTrie() {
        trie=new TrieNode();
        
        for(int i=0;i<words.size();i++) {
            TrieNode* temp=trie;
            for(int j=0;j<words[i].size();j++) {
                char c=words[i][j];
                if(temp->m.find(c)==temp->m.end()) {
                    temp->m[c]=new TrieNode();
                    temp=temp->m[c];
                } else {
                    temp=temp->m[c];
                }
            }
            temp->isTerminal=true;
        }
    }

    bool isPrefix(string prefix) {

        TrieNode* temp=trie;

        for(char c:prefix) {
            if(temp->m.find(c)==temp->m.end()) return false;
            else temp=temp->m[c];
        }
        return true;
    }

    void bt(int x,int y) {

        if(s.find(curr)!=s.end()) {
            ans.push_back(curr);
            s.erase(curr);
        }
        

        for(int i=0;i<4;i++) {
            int xx=x+dir[i][0];
            int yy=y+dir[i][1];

           
            if(xx>=0 && xx<n && yy>=0 && yy<m && vis[xx][yy]==0) {
                
                curr+=board[xx][yy];
                vis[xx][yy]=1;
                if(isPrefix(curr)) {
                    bt(xx,yy);
                }
                vis[xx][yy]=0;
                curr.pop_back();
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->n=board.size();
        this->m=board[0].size();

        this->board=board;
        this->words=words;

        this->dir={{1,0},{-1,0},{0,1},{0,-1}};
        this->ans.clear();
        this->curr="";

        vis.assign(n,vector<int>(m,0));

        buildTrie();


        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                curr+=board[i][j];
                vis[i][j]=1;
                bt(i,j);
                vis[i][j]=0;
                curr.pop_back();
            }
        }

        return  ans;   
    }
};
*/