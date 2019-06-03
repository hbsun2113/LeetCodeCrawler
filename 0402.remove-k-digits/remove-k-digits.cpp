class Solution {
public:
    
    // 二刷
    /*The intuition is, when you see a digit, you are not sure whether you should use or drop the digit, so you just save it into the stack for better decision later. When there is a better candidate (a smaller digit) to use, you drop the saved bigger digit from the stack. Look carefully, the elements in the stack are kept in increasing order. So when a new candidate comes up, you can do a comparison to remove one or more of the saved digits, until you meet one in the stack that is not larger than the candidate.

This kind of stack is called Monotonous Increase Stack. See this post for more info. At the end, it lists other problems that can solved using such kind of stack.
https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step
    */
    string removeKdigits(string num, int k) {
        stack<char> s; // 单调递增栈,用来排除掉大元素
        for(const auto &c:num){
            while(!s.empty() && c<s.top() && k>0){ // 我们要做的是在有效k内，尽量给高位按上小元素
                s.pop();
                k--;
            } 
            s.push(c);
        }
        string res;
        while(!s.empty() && k>0){
            s.pop();
            k--;
        } 
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        while(res.back()=='0') res.pop_back();
        if(res.size()==0) return "0";
        reverse(res.begin(),res.end());
        return res;
    }
    
    
    string removeKdigits1(string num, int k) {
        string res;
        for(int i=0;i<num.size();i++){
            while(!res.empty() && k>0 && res.back()>num[i]){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k>0){
            res.pop_back();
            k--;
        }
        while(res[0]=='0') res.erase(res.begin());
        if(res.size()==0) return "0";
        return res;
    }
};