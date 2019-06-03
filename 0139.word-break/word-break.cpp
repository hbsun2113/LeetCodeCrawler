// Trie树对DP进行优化
// https://leetcode.com/problems/word-break/discuss/43790/Java-implementation-using-DP-in-two-ways 的评论 
class TrieNode{
public:
    vector<TrieNode*> son;
    bool isend;
    
    TrieNode():isend(false){
        son.clear();
        son.resize(26);
    }
};

class Solution {
public:
    TrieNode *root=new TrieNode();
    
    void addnode(string &w){
        auto curr=root;
        for(const auto &c:w){
            if(curr->son[c-'a']==nullptr) curr->son[c-'a']=new TrieNode();
            curr=curr->son[c-'a'];
        }
        curr->isend=true;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &w:wordDict){
            addnode(w);
        }
        
        int n=s.size();
        vector<bool> f(n+1);
        f[n]=true; // f[i]代表以i为起点的字符串，可以被字典分割
        for(int i=n-1;i>=0;i--){ // 注意，是从后往前遍历
            // 这个做法是错误的，curr一定要从root开始，否则对于单个字符的case有问题
            // auto curr=root->son[s[i]-'a'];
            // for(int j=i+1;j<n;j++){
            auto curr=root;
            for(int j=i;j<n;j++){ // 注意，是从前往后遍历
                if(!curr) break;
                curr=curr->son[s[j]-'a'];
                if(curr!=nullptr && curr->isend && f[j+1]){
                    f[i]=true;
                    break;
                }
            }
        }
        
        return f[0];
    }
    
    
    
    
    // 二更,发现使用Word Break II的方法没有办法AC,会超时。还得是使用下面的方法啊！
    // 这道题目要记住使用动归解
    // 这个做法不好
    unordered_set<string> us;
    bool wordBreak1(string s, vector<string>& wordDict) {
        return helper(s,wordDict);
    }
    
    bool helper(string s, vector<string>& wordDict){
        if(find(wordDict.begin(),wordDict.end(),s) != wordDict.end() ) return true;
        for(int i=1;i<=s.size();i++){
            string first=s.substr(0,i);
            if( find(wordDict.begin(),wordDict.end(),first) != wordDict.end() ){
                string second=s.substr(i);
                if(helper(second,wordDict)){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    
    
    
    

    
    
    
    
    
    // 三刷
    // dfs+memorize 慢！
    unordered_map<string,bool> um;
    bool wordBreak2(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        for(auto &w:wordDict) us.emplace(w);
        return dfs(s);
    }
    
    bool dfs(const string s){
        if(um.find(s)!=um.end()) return um[s];
        for(int i=1;i<=s.size();i++){
            const string &a=s.substr(0,i);
            const string &b=s.substr(i);
            if(us.find(a)==us.end()) continue;
            // cout<<a<<" "<<b<<endl;
            if(b.size()==0 || dfs(b)){
                um[s]=true;
                return true;
            } 
        }
        um[s]=false;
        return false;
    }
    
    
    
    
    
    //https://discuss.leetcode.com/topic/7299/c-dynamic-programming-simple-and-fast-solution-4ms-with-optimization
    
    //http://blog.csdn.net/worldwindjp/article/details/18987825
    //我们定义状态数组：state[s.length()+1]，state[i]代表：string[0,i-1] 可被字典中的单词分割。
    
    
    bool wordBreak3(string s, vector<string>& wordDict) {
        for(const auto &w:wordDict) us.emplace(w);
        vector<bool> result(s.size()+1,false);
        result[0]=true;
        for(int i=1;i<s.size()+1;i++){
            for(int j=0;j<i;j++){
                if(result[j] && us.find(s.substr(j,i-j))!=us.end()){
                    result[i]=true;
                    break;
                }
            }
        }
        return result[s.size()];
    }
};