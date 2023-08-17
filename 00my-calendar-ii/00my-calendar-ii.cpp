class MyCalendarTwo {
    map<int,int> m;
public:
    MyCalendarTwo() {
        m.clear();
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;

        int count=0;
        for(auto e:m) {
            count+=e.second;

            if(count>2) {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */