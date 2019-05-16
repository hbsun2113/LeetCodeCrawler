class Solution {
public:
    //https://www.acwing.com/solution/LeetCode/content/75/
    // 记住2n-2这个！
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int len=numRows*2-2;
        string res="";
        for(int i=0;i<numRows;i++){
            if(i==0 || i==numRows-1){
                for(int j=i;j<s.size();j+=len)
                    res+=s[j];
            }
            else{
                for(int j=i,k=len-i;(j<s.size() || k<s.size()) ; j+=len,k+=len)
                {
                    if(j<s.size()) res+=s[j];
                    if(k<s.size()) res+=s[k];
                }
            }
        }
        return res;
    }
};