//https://leetcode.com/problems/finding-mk-average/discuss/1152724/C%2B%2B-Balance-3-Multisets

class MKAverage {
    int m = 0, k = 0, sz = 0, pos = 0;
    long sum = 0;
    vector<int> v;
    multiset<int> left, mid, right;
public:

    void remove(int n) 
    {
        if (n <= *prev(left.end()))
            left.erase(left.find(n));
        else if (n <= *prev(mid.end()))
        {
           auto it = mid.find(n); 
           sum -= *it;
           mid.erase(it);
        }
        else
            right.erase(right.find(n));
        
        if (left.size() < k) {
            left.insert(*mid.begin());
            sum -= *mid.begin();
            mid.erase(mid.begin());
        }
        if (mid.size() < sz) {
            mid.insert(*right.begin());
            sum += *right.begin();
            right.erase(right.begin());
        }
    }
    
    void add(int n) 
    {
        left.insert(n);
        if (left.size() > k) {
            auto it = prev(left.end());
            mid.insert(*it);
            sum += *it;
            left.erase(it);
        }
        if (mid.size() > sz) {
            auto it = prev(mid.end());
            sum -= *it;
            right.insert(*it);
            mid.erase(it);
        }
    }
    
    MKAverage(int m, int k) : m(m), k(k), sz(m - 2 * k) 
    {
        v = vector<int>(m);
    }
    
    void addElement(int num) 
    {
        if (pos >= m)
            remove(v[pos % m]);
        add(num);
        v[pos++ % m] = num;
    }
    
    int calculateMKAverage() 
    {
        if (pos < m)
            return -1;
        return sum / sz;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */