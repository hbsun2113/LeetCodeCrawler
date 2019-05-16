class Solution {
public:
    //二更,发现使用Word Break II的方法没有办法AC,会超时。还得是使用下面的方法啊！
    // 这道题目要记住使用动归解
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
    
    
    
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    //https://discuss.leetcode.com/topic/7299/c-dynamic-programming-simple-and-fast-solution-4ms-with-optimization
    
    //http://blog.csdn.net/worldwindjp/article/details/18987825
    //我们定义状态数组：state[s.length()+1]，state[i]代表：string[0,i-1] 可被字典中的单词分割。
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
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