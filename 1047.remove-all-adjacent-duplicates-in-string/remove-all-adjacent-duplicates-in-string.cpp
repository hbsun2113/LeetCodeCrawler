class Solution {
public:
    // 别人的解法
    string removeDuplicates(string S) {
        string res;
        for(const auto &c:S){
            if(res.size() && res.back()==c)
                res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
    
    // 自己的解法，差距啊
    string removeDuplicates1(string S) {
        string tmp;
        int i=0;
        bool flag=true;
        while(i<S.size()){
            int j=i+1;
            bool tflag=true;
            if(j<S.size() && S[i]==S[j]){
                j++;
                tflag=false;
                flag=false;
            } 
            if(tflag) tmp+=S[i];
            i=j;
        }
        // cout<<tmp<<endl;
        if(flag) return tmp;
        else return removeDuplicates(tmp);
    }
};