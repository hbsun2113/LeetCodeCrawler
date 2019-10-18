class MyStack {
public:
    // ??????????????????
    // https://leetcode.com/problems/implement-stack-using-queues/discuss/62527/A-simple-C++-solution
    // ??????push(x)??x???front
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    // ??????
    void reset(){
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        } 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        cout<<"push:"<<x<<endl;
        reset();
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        cout<<"pop"<<endl;
        reset();
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        auto v=q1.front();
        q1.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        reset();
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        auto v=q1.front();
        q2.push(v);
        q1.pop();
        cout<<"top finish"<<endl;
        return v;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        cout<<"empty"<<endl;
        return q1.empty() && q2.empty();
    }
    
    
    queue<int> q1,q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */