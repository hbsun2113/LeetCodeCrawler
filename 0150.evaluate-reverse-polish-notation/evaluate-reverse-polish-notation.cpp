class Solution {
//自己做的，思想比较简单。遇到数字压栈；遇到符号，从栈里弹出两个数字进行运算，再压栈。最后的结果就是栈里那个唯一的数字。
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
        for(auto t:tokens){
            if(isdigit(t[0]) || (t[0] == '-' && isdigit(t[1]))) q.push(atoi(t.c_str()));
            else{
                int x=q.top();
                q.pop();
                int y=q.top();
                q.pop();
                q.push(op(y,x,t));
            }
        }
        return q.top();
    }
    
    
    
    int op(int x,int y,string c){
        if(c=="+") return x+y;
        if(c=="-") return x-y;
        if(c=="*") return x*y;
        if(c=="/") return x/y;
        else cout<<c<<endl;
    }

};