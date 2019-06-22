class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        int n=words.size();
        if(n==0) return 0;
        
        vector<int> mask(n);
        for(int i=0;i<words.size();i++){
            string w=words[i];
            int m=0;
            for(int j=0;j<w.size();j++){
                int t=w[j]-'a';
                m|=(1<<t);
            }
            mask[i]=m;
        }
        
        int res=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((mask[i] & mask[j])==0) 
                    res=max(res,(int)words[i].size()*(int)words[j].size());
            }
        }
        
        return res;
    }
    
    
    
    // 暴力解法，没意思
    int maxProduct1(vector<string>& words) {
        int res=0;
        if(words.size()==0) return 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j])) res=max(res,(int)words[i].size()*(int)words[j].size());
            }
        }
        return res;
    }
    bool check(string &a, string &b){
        vector<int> vec(29,0);
        for(const auto &c:a) vec[c-'a']++;
        for(const auto &c:b){
            if(vec[c-'a']!=0) return false;
        }
        return true;
    }
};