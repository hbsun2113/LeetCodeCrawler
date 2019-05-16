/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (23.29%)
 * Total Accepted:    239.6K
 * Total Submissions: 1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    //完全参照别人的代码写的，没有思路https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS    
    //好像还有其他解法，Two-end Search。
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset;
        for(auto w:wordList) wordset.insert(w);
        queue<string> path;
        int length=2;
        addnode(beginWord,path,wordset);
        while(!path.empty()){
            int num=path.size();
            for(int i=0;i<num;i++){
                string tmp=path.front();
                path.pop();
                if(tmp==endWord) return length;
                addnode(tmp,path,wordset);
            }
            length++;
        }
        return 0;
    }
    
    void addnode(string beginWord, queue<string>& path, unordered_set<string>& wordset){
        wordset.erase(beginWord);
        for(int i=0;i<beginWord.size();i++){
            char c=beginWord[i];
            for(int j=0;j<26;j++){
                beginWord[i]='a'+j;
                if(wordset.find(beginWord)!=wordset.end()){
                    path.push(beginWord);
                    wordset.erase(beginWord);
                }
            }
            beginWord[i]=c;
        }
    }




    // 超时解法,他的问题是去遍历wordList去寻找合适的解，当wordList很大的时候就很耗时。
    bool check(string a, string b){
        int res=0;
        for(int i=0;i<a.size();i++)
            res+=(a[i]!=b[i]);
        return res==1;
    }
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um;
        queue<string> q;
        q.emplace(beginWord);
        um[beginWord]=1;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            if(tmp==endWord) return um[tmp];
            for(const auto &word:wordList){
                if(check(word,tmp) && !um[word]){
                    um[word]=um[tmp]+1;
                    q.emplace(word);
                }
            }
        }
        return 0;
    }

    // 改进版,注意啊只能遍历26个字符。
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um;
        unordered_set<string> us(wordList.begin(),wordList.end());
        queue<string> q;
        q.emplace(beginWord);
        um[beginWord]=1;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            if(tmp==endWord) return um[tmp];
            us.erase(tmp);
            for(int i=0;i<tmp.size();i++){
                char c=tmp[i];
                int count=um[tmp];
                for(int j=0;j<26;j++){
                    tmp[i]='a'+j;
                    if(us.find(tmp)!=us.end()){
                        q.emplace(tmp);
                        us.erase(tmp);
                        um[tmp]=count+1;
                    }
                }
                tmp[i]=c;
            }
        }
        return 0;
    }

};

