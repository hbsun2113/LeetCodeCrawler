class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int qn=queries.size();
        int wn=words.size();
        vector<int> qvec(qn),wvec(wn);
        for(int i=0;i<qn;i++) 
            qvec[i]=f(queries[i]);
        for(int j=0;j<wn;j++)
            wvec[j]=f(words[j]);
        vector<int> res(qn);
        for(int i=0;i<qn;i++){
            for(int j=0;j<wn;j++){
                if(qvec[i]<wvec[j]) res[i]++;
            }
        }
        return res;
    }
    
    int f(string &s){
        if(s.size()==0) return 0;
        auto c=s[0];
        for(int i=1;i<s.size();i++)
            c=min(c,s[i]);
        int cnt=0;
        for(int i=0;i<s.size();i++)
            cnt+=(c==s[i]);
        return cnt;
    }
};