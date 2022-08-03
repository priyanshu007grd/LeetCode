class MyCalendar {
public:
    vector<pair<int,int>> bookingList;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        //cout<<start<<"  "<<end<<endl;
        for(auto [s,e] : bookingList)
        {
            if( max(s,start)<min(e,end) )
            {
                //cout<<booking.first<<"  "<<booking.second<<endl;
                //cout<<endl;
                return false;
            }
                
        }
        bookingList.push_back({start,end});
        //cout<<endl;
        return true;
    }
};

// class MyCalendar {
//     map<int,int> m;
// public:
//     MyCalendar() {
//         m.clear();
//     }
    
//     bool book(int start, int end) {
        
//         auto it = m.upper_bound(start);
        
//         if(it!=m.begin() && prev(it)->second > start) return false;
//         if(it!=m.end() && it->first<end) return false;
        
//         m[start]=end;
//         return true;
        
//     }
// };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */