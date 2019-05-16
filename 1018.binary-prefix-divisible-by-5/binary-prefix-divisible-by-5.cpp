class Solution {
public:
    // 这是leetcode contest的题目
    
    // 高手做的
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum = ((sum * 2) + A[i]) % 5;
            if (sum == 0) ret.push_back(true);
            else ret.push_back(false);
        }
        return ret;
    }
    
    // 自己做的
    vector<bool> prefixesDivBy51(vector<int>& A) {
        vector<bool> res;
        long long curr=0;
        for(const auto &a:A){
            curr*=2;
            curr+=a;
            if(curr>10) curr%=10;  //每次都是取尾数部分
            cout<<curr<<endl;
            if(curr%5==0){
                res.push_back(true);
            }
            else res.push_back(false);
        }
        return res;
    }
};