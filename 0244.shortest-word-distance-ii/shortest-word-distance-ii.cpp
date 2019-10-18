class WordDistance {
public:
    // ???????????????https://leetcode.com/problems/shortest-word-distance-ii/discuss/67028/Java-Solution-using-HashMap
    unordered_map<string,vector<int>> um;
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            um[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res=INT_MAX;
        for(auto &x:um[word1]){
            for(auto &y:um[word2]){
                res=min(res,abs(x-y));
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */