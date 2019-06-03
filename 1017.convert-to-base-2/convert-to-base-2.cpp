class Solution {
public:
    // https://www.bilibili.com/video/av51966443
    // 以后优选位运算
    string baseNeg22(int N) {
        if(N==0) return "0";
        string res="";
        while(N!=0){
            res+=to_string(N&1); // 最低位，无论奇偶，都是1，所以可以这么做
            N=-(N>>1); // 因为是除以-2，所以每次要改变符号
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    
    string baseNeg2(int N) {
        if(N==0) return "0";
        string res="";
        while(N!=0){
            res+=to_string(N&1); // 最低位，无论奇偶，都是1，所以可以这么做
            if(N%2!=0) N--;
            N/=-2; 
        }
        reverse(res.begin(),res.end());
        return res;
    }
};