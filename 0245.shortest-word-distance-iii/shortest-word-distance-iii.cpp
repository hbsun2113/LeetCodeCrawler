class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1=-1,p2=-1;
        int res=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==word1) p1=i;
            if(p1!=-1 && p2!=-1 && p1!=p2) res=min(res,abs(p1-p2));
            if(words[i]==word2) p2=i;
            if(p1!=-1 && p2!=-1 && p1!=p2) res=min(res,abs(p1-p2));
        }
        return res;
        
    }
};