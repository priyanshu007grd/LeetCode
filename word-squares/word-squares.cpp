/*
this problem can also be solved using tri but that will not improve time complexity or space complexity
*/
class Solution {
    vector<string> words;
    int wSize;
    vector<vector<string>> ans;
    vector<string> curr;
    map<string,vector<int>> m;
public:
    vector<string> getCadidateWord(string prefix) {
        vector<string> candidateWords;

        for(int i=0;i<m[prefix].size();i++) {
            candidateWords.push_back(words[m[prefix][i]]);
        }

        return candidateWords;
    }

    void bt(int step) {
        if(step>=wSize){
            ans.push_back(curr);
            return;
        }

        string prefix ="";
        for(int i=0;i<curr.size();i++) prefix+=curr[i][step]; 
        vector<string> candidateWords = getCadidateWord(prefix);

        for(int i=0;i<candidateWords.size();i++) {
            curr.push_back(candidateWords[i]);
            bt(step+1);
            curr.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        this->wSize=words[0].size();
        this->words=words;
        m.clear();

        for(int i=0;i<words.size();i++) {
            string prefix="";
            m[prefix].push_back(i);
            for(int j=0;j<words[i].size();j++) {
                prefix+=words[i][j];
                m[prefix].push_back(i);
            }
        }
        bt(0);
        return ans;
    }
};
/*
// Backtracking approch : TLE
class Solution {
    vector<string> words;
    int wSize;
    vector<vector<string>> ans;
    vector<string> curr;
public:
    vector<string> getCadidateWord(string prefix) {
        vector<string> candidateWords;

        for(string word:words) {
            if(word.substr(0,prefix.size())==prefix) candidateWords.push_back(word);
        }
        return candidateWords;
    }

    void bt(int step) {

        if(step>=wSize){
            ans.push_back(curr);
            return;
        }

        string prefix ="";
        for(int i=0;i<curr.size();i++) prefix+=curr[i][step]; 
        vector<string> candidateWords = getCadidateWord(prefix);

        for(int i=0;i<candidateWords.size();i++) {
            curr.push_back(candidateWords[i]);
            bt(step+1);
            curr.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        this->wSize=words[0].size();
        this->words=words;
        bt(0);
        return ans;
    }
};
*/