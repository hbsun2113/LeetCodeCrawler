class Solution {
public:
    // 更通用的做法:https://www.acwing.com/solution/LeetCode/content/321/
    
    // https://leetcode.com/problems/basic-calculator/discuss/62361/Iterative-Java-solution-with-stack?orderBy=most_votes
    // 实现不难，主要就是思路要清晰，争取自己做出来。
    // 如果实在自己做不出来，代码结构和主要原则就记住吧。
    int calculate(string str) {
        str.push_back('+');
        int res=0,num=0;
        stack<int> s;
        int sign=1;
        s.push(1);
        for(const auto &c:str){
            if(c>='0' && c<='9'){
                num*=10;
                num+=(c-'0');
            }
            else if(c=='+' | c=='-'){
                res+=sign*num;
                // cout<<sign*num<<endl;
                num=0;
                sign=s.top()*(c=='+'?1:-1);
            }
            else if(c=='('){
                s.push(sign);
            }
            else if(c==')'){
                s.pop();
            }
        }
        return res;
    }
};


/*
栈用来保存整体括号的符号状态。
Principle:

(Sign before '+'/'-') = (This context sign); 这个context是指代码中的num
(Sign after '+'/'-') = (This context sign) * (1 or -1);
Algorithm:

Start from +1 sign and scan s from left to right;
if c == digit: This number = Last digit * 10 + This digit;
if c == '+': Add num to result before this sign; This sign = Last context sign * 1; clear num;
if c == '-': Add num to result before this sign; This sign = Last context sign * -1; clear num;
if c == '(': Push this context sign to stack;
if c == ')': Pop this context and we come back to last context;
Add the last num. This is because we only add number after '+' / '-'.
*/