class Solution {
public:
    // ????? one pass?https://leetcode.com/problems/shortest-word-distance/discuss/66931/AC-Java-clean-solution
    
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>> um;
        for(int i=0;i<words.size();i++){
            um[words[i]].push_back(i);
        }
        
        int res=INT_MAX;
        for(auto &x:um[word1]){
            for(auto &y:um[word2]){
                res=min(res,abs(x-y));
            }
        }
        
        return res;
    }
};