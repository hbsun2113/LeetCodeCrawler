class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        vector<int> res(n);
        if(n==0) return res;
        for(int i=n-1;i>=0;i--){
            carry+=digits[i];
            res[i]=carry%10;
            carry/=10;
        }
        if(carry==1) res.insert(res.begin(),1);
        return res;
    }
};