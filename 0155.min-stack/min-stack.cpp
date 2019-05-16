class MinStack {
public:
    //https://www.acwing.com/solution/LeetCode/content/249/
    // 自己没有做出来，是因为还不能熟练使用单调栈。
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s_value.push(x);
        // 如果x小于当前s_min的栈顶自然是要入栈。
        // 但如果x大于s_min的栈顶则不必再入栈了。因为此时的最小值还是s_min的栈顶，并且这个栈顶是要后于x出s_value栈的,
        // 也就是说x任何时候都起不到最小值的作用。
        if(s_min.empty() || x<=s_min.top()) s_min.push(x);  
    }
    
    void pop() {
        int value=s_value.top();
        s_value.pop();
        // 如果要从s_value出栈，并且之前一直起到了最小值的作用，则它也要从s_min出栈。
        if(value==s_min.top())
            s_min.pop();
    }
    
    int top() {
        return s_value.top();
    }
    
    int getMin() {
        return s_min.top();
    }
    
    //https://www.acwing.com/solution/LeetCode/content/249/ 注意使用单调栈，利用了栈先进后出的特性。
    stack<int> s_value;
    stack<int> s_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */