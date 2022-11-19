class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = s.end();
    
    SORTracker() 
    {
        s.clear();
        it=s.end();
    }
    void add(string name, int score) 
    {
        auto it1 = s.insert({-score, name}).first;
        if (it == end(s) || *it1 < *it)
            --it;
    }
    string get() 
    {
        return (it++)->second;
    }
};
/*
// TLE
class SORTracker {
    set<pair<int, string>> s;
    int i=0;
public:
    SORTracker() 
    {
        s.clear();
    }
    
    void add(string name, int score) 
    {
        s.insert({-score, name});
    }
    
    string get() 
    {
        auto it = next(s.begin(),i);
        i++;
        return (*it).second;
    }
};
*/

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */