typedef pair<int,string> T;
class TrieNode {
public:
    int count;
    unordered_map<char,TrieNode*> m;
};

struct cmp {
	bool operator()(const T& x, const T& y) { 
        if(x.first==y.first) return x.second<y.second;
        return x.first>y.first;
    }
};
class AutocompleteSystem {
    TrieNode* trie;
    TrieNode* temp;
    string prefix;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie=new TrieNode();
        int n=sentences.size();
        
        for(int i=0;i<n;i++) {
            TrieNode* temp=trie;
            for(int j=0;j<sentences[i].size();j++) {
                int c=sentences[i][j];
                
                if(temp->m.find(c)==temp->m.end()) {
                    temp->m[c]=new TrieNode();
                    temp=temp->m[c];
                } else {
                    temp=temp->m[c];
                }
            }
            temp->count=times[i];
        }
        temp=trie;
    }
    
    vector<string> input(char c) {
        
        if(c=='#') {
            temp->count++;
            temp=trie;
            prefix="";
            return vector<string>();
        } else {
            prefix+=c;
            if(temp->m.find(c)==temp->m.end()) {
                temp->m[c]=new TrieNode();
                temp=temp->m[c];
            } else {
                temp=temp->m[c];
            }
            
            vector<string> ans;
            priority_queue<T,vector<T>,cmp> pq;
            getSentence(temp,prefix, pq);
            
            int cc=3;
            while(!pq.empty() && cc--) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    }
    
    void getSentence(TrieNode* temp,string prefix,priority_queue<T,vector<T>,cmp>& pq) {
        
        if(temp->count>0) {
            pq.push({temp->count,prefix});
            if(pq.size()>3) pq.pop();
        }
        
        for(auto it:temp->m) {
            char c=it.first;
            getSentence(temp->m[c],prefix+c,pq);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */