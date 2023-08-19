class Logger {
    map<string,int> m;
public:
    Logger() {
        m.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(m.find(message)!=m.end()) {
            if(m[message]+10<=timestamp) {
                m[message]=timestamp;
                return true;
            }
            return false;
        } else {
            m[message]=timestamp;
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */