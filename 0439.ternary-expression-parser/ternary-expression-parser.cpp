class Solution {
public:
    string parseTernary(string expression) {
        if(expression.size()==0) return expression;
        stack<char> s;
        for(int i=expression.size()-1;i>=0;i--){
            if(!s.empty() && s.top()=='?'){
                s.pop();
                auto first=s.top();
                s.pop();
                s.pop();
                auto second=s.top();
                s.pop();
                if(expression[i]=='T') s.push(first);
                else s.push(second);
            }
            else 
                s.push(expression[i]);
        }
        
        string res="";
        return res+s.top();
    }
};