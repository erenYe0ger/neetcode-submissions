class MinStack {
    stack<int> values, mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        values.push(val);
        if(mini.empty() ||
            val <= mini.top()) mini.push(val);
    }
    
    void pop() {
        int val = values.top();
        values.pop();
        if(val == mini.top()) mini.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
