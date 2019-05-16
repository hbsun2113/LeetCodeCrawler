class Solution {
public:
    
    
    
    
    
    
    
    
    // 自己想到了解法，有些细节参考了https://leetcode.com/problems/remove-duplicate-letters/discuss/76853/4ms-C++-solution-use-return-string-as-a-stack
    
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> um;
        unordered_set<char> us; 
        for(const auto& c:s) um[c]++;
        stack<char> st; // 使用单调栈排除比自己大并且后面还可以再出现的元素
        for(const auto &c:s){
            um[c]--; // 标志它是否已经是最后一个可用字符了。比如有3个b，标志的是它是否是最后一个b，如果是就不得不用它了，不可以被弹出。
            if(us.find(c)!=us.end()) continue;  //标志它是否已经在前面出现了并且仍然有效，如果是就不必再考虑他了。
            while(!st.empty() && st.top()>=c && um[st.top()]>=1){ //如果栈顶字符比自己大，而且在后面还能出现，那就弹出栈顶。
                us.erase(st.top());
                st.pop();   
            }
            if(us.find(c)==us.end()){
                st.push(c);
                us.emplace(c);
            }  
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};