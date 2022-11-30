/*
edge case where order of erase is very important

    eg 1                            ["RandomizedCollection","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom,"getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]


eg 2
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]

*/
class RandomizedCollection 
{
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
public:
    RandomizedCollection() 
    {
        v.clear();
        m.clear();
    }
    
    bool insert(int val) 
    {        
        v.push_back(val);
        m[val].insert(v.size()-1);
        return m[val].size()==1;
    }
    
    bool remove(int val) 
    {              
        if(m.find(val)==m.end()) return false;
        
        int i=*(m[val].begin());
        int j=v.size()-1;
        
        v[i]=v[j];
        
        //order of erase is very important
        m[val].erase(i);
        m[v[j]].insert(i);
        m[v[j]].erase(j);
        
        v.pop_back();
        
        if(m[val].size()==0) m.erase(val);
        
        return true;
    }
    
    int getRandom()
    {

        return v[rand() % v.size()];
    }
    
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */