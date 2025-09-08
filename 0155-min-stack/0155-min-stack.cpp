class MinStack {
private:
    stack<int> st, minSt;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()) minSt.push(val);
        else minSt.push(minSt.top()); // Keep previous min
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};