class Solution {
public:
    // 之前写的都太麻烦了,以后还是用这个吧:
    // https://leetcode.com/problems/basic-calculator-ii/discuss/257497/Easy-read-c++-solution
    // 并且记住规则：遇到+-进栈，遇到*／直接操作
    int calculate(string s) {
        char op;
        int n;
        istringstream ins("+"+s);
        stack<int> st;
        while(ins>>op>>n){
            if(op=='+'){
                st.push(n);
                continue;
            }
            if(op=='-'){
                st.push(-n);
                continue;
            }
            if(op=='*'){
                int tmp=st.top()*n;
                st.pop();
                st.push(tmp);
                continue;
            }
            if(op=='/'){
                int tmp=st.top()/n;
                st.pop();
                st.push(tmp);
                continue;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};