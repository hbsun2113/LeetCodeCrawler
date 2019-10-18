class Solution {
public:
    // ????????????make sense:https://leetcode.com/problems/string-without-aaa-or-bbb/discuss/226649/JavaC++-(and-Python)-simple-greedy
    string strWithout3a3b(int A, int B) {
        string res="";
        int sum=A+B;
        bool flag=true; // flag??????????A?????B?????A??????B???
        if(A<B) flag=false;  
        while(res.size()<sum){
            if(flag){
                if(A>B && A>=2){
                    res+="aa";
                    A-=2;
                }
                else if(A>=1){
                    res+="a";
                    A-=1;
                }
            }
            else{
                if(B>A && B>=2){
                    res+="bb";
                    B-=2;
                }
                else if(B>=1){
                    res+="b";
                    B-=1;
                }
            }
            flag=!flag;
        }
        return res;
    }
};