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
        // cout<<"insert "<<val<<endl;
        // print(v);
        // print(m);
        
        v.push_back(val);
        m[val].insert(v.size()-1);
        
        // print(v);
        // print(m);
        
        return m[val].size()==1;
    }
    
    bool remove(int val) 
    {      
        // cout<<"remove "<<val<<endl;
        // print(v);
        // print(m);
        
        if(m.find(val)==m.end()) return false;
        
        int i=*(m[val].begin());
        int j=v.size()-1;
        
        v[i]=v[j];
        
/*
order of erase is very important

    eg 1                            ["RandomizedCollection","insert","remove","insert","remove","getRandom","getRandom","getRandom","getRandom,"getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[0],[0],[-1],[0],[],[],[],[],[],[],[],[],[],[]]


eg 2
["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
[[],[1],[1],[2],[1],[2],[2],[1],[2],[2],[2],[],[],[],[],[],[],[],[],[],[]]

*/
        m[val].erase(i);
        m[v[j]].insert(i);
        m[v[j]].erase(j);
        
        v.pop_back();
        
        if(m[val].size()==0) m.erase(val);
        
        // print(v);
        // print(m);
        
        return true;
    }
    
    int getRandom()
    {
        // cout<<"getRandom "<<v[rand() % v.size()]<<endl;
        // print(v);
        // print(m);
        return v[rand() % v.size()];
    }
    
    void print(vector<int> v)
    {
        cout<<"vector print"<<endl;
        for(auto i:v) cout<<i<<"    ";
        cout<<endl;
    }
    void print(unordered_map<int, unordered_set<int>> m)
    {
        cout<<"map print"<<endl;
        for(auto i:m)
        {
            cout<<"val "<<i.first<<endl;
            cout<<"pos ";
            for(auto j:i.second)
            {
                cout<<j<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */