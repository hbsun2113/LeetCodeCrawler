class Solution {
public:
    bool isValid(string ss) {
        stack<char> s;
        for(auto cc:ss){
            if(cc=='(') s.push(cc);
            else if(cc==')'){
                if(s.empty()) return false;
                if(s.top()!='(') return false;
                else s.pop();
            }
            else if(cc=='[') s.push(cc);
            else if(cc==']'){
                if(s.empty()) return false;
                if(s.top()!='[') return false;
                else s.pop();
            }
            else if(cc=='{') s.push(cc);
            else if(cc=='}'){
                if(s.empty()) return false;
                if(s.top()!='{') return false;
                else s.pop();
            }
            
        }
        if(!s.empty()) return false;
        return true;
    }
};