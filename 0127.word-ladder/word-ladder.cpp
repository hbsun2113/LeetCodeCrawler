class Solution {
public:
    
    
    // 自己做出来了：最短，首选bfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um;
        for(const auto &w:wordList) um[w]=1;
        
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            auto rem=t.second;
            
            for(int i=0;i<t.second.size();i++){
                t.second=rem;
                for(char c='a';c<='z';c++){
                    t.second[i]=c;
                    if(um.find(t.second)==um.end() || um[t.second]>1) continue;
                    if(t.second==endWord) return t.first+1;
                    q.push({t.first+1,t.second});
                    // cout<<t.first+1<<" "<<t.second<<endl;
                    um[t.second]++;
                }
            }
            
        }
        return 0;
    }
    
    
    //完全参照别人的代码写的，没有思路https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS    
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


    //Two-end Search
    int ladderLength5(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(),wordList.end()};
        unordered_set<string>begin{beginWord};
        unordered_set<string>end{endWord};
              
        
        if(!dict.count(endWord))
            return 0;
        
        int len=1;
        
        while((!begin.empty())&&(!end.empty())){
            len++;
            if(begin.size()>end.size()){
                // https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C++-Solution-using-BFS
                // 利用了指针，我觉得没有必要，直接swap啊，运行非常高效
                swap(begin,end); 
            }
            unordered_set<string> childs;
            for(string tmp : begin){
                for(int i=0;i<beginWord.size();i++){
                    char orig=tmp[i];
                    for(int j='a';j<='z';j++){
                        tmp[i]=j;
                        if(end.count(tmp))
                            return len;
                        if(dict.count(tmp)){
                            childs.insert(tmp);
                            dict.erase(tmp);
                        }
                    }
                    tmp[i] = orig;
                }
            }
            begin = childs;
        }
        
        return 0;
    }


    
    
    
    
    
    
    // 超时解法,他的问题是去遍历wordList去寻找合适的解，当wordList很大的时候就很耗时。
    // https://www.acwing.com/solution/LeetCode/content/221/
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

    // 改进版
    int ladderLength3(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> um;
        unordered_set<string> us(wordList.begin(),wordList.end());
        queue<string> q;
        q.emplace(beginWord);
        um[beginWord]=1;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            if(tmp==endWord) return um[tmp];
            int count=um[tmp];
            for(int i=0;i<tmp.size();i++){
                char c=tmp[i];
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

