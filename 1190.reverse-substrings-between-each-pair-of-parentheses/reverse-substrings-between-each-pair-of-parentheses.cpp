class Solution {
public:
    // https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/382422/0-ms-stack-solution-C-++
    // ???Weekly Contest 154  ??????????????????
    // ????stack,???????????????????????????????stack??????
    string reverseParentheses(string ss) {
        stack<int> s;
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='(') s.push(i);
            else if(ss[i]==')'){
                reverse(ss.begin()+s.top(),ss.begin()+i);
                s.pop();
            }
        }
        
        string res="";
        for(const auto &c:ss){
            if(isalpha(c)) res+=c;
        }
        
        return res;
    }
};