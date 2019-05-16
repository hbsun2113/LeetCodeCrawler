class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(int i=0;i<num.size();i++){
            while(!res.empty() && k>0 && res.back()>num[i]){
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k>0){
            res.pop_back();
            k--;
        }
        while(res[0]=='0') res.erase(res.begin());
        if(res.size()==0) return "0";
        return res;
    }
};