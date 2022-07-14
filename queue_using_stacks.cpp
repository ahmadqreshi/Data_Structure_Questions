class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() { 
    }
    
    void push(int x) {
        while(st1.size()!=0) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(st2.size()!=0) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int n = st1.top();
        st1.pop();
        return n;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
       return st1.empty() ? true : false;
    }
};
