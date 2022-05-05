// pop operation O(1) = https://leetcode.com/problems/implement-stack-using-queues/discuss/62527/A-simple-C%2B%2B-solution
class MyStack {
    int topV;
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        topV=x;
    }
    
    int pop() {
        
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            topV=q.front();
            q.pop();
        }
        int t=q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return topV;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */