class Solution {
public:
    // 这道题目重点在于ju
    int longestStrChain(vector<string>& words) {
        if(words.size()==0) return 0;
        auto cmp=[](string &a, string &b){
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),cmp);
        vector<int> vec(words.size(),1);
        int res=1;
        int k=0;
        for(int i=0;i<words.size();i++){
            for(int j=i-1;j>=0;j--){
                if(words[i].size()-words[j].size()==1 && ju1(words[j],words[i])){
                    vec[i]=max(vec[i],vec[j]+1);
                    res=max(res,vec[i]);
                }   
            }
        }
        return res;
    }
    
    bool ju(const string &a, const string &b){
        if (a.size() + 1 != b.size())
        return false;
        int n = a.size();
        for (int i = 0; i <= n; i++) // 每次忽略掉b[i]
            if (a == b.substr(0, i) + b.substr(i + 1))
                return true;
        return false;
    }
    
    // 自己写的，参考别人的
    bool ju1(const string &a, const string &b){
        int la=a.size(),lb=b.size();
        int i=0,j=0;
        int count=0; // 不一致的个数
        while(j<lb){
            while(j<lb && i<la && a[i]==b[j]) i++,j++;
            if(j==lb || i==la) return true;
            count++;
            j++;
            if(count>1) return false;
        }
        return true;
        
    }
};
