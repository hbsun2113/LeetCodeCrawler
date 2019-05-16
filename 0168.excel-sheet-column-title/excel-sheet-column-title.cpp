class Solution {
public:
    //这么简单的一道题目我竟然没有做出来！！！！！！！！！！！！！！！！啊啊啊啊啊啊新心情好差啊！！！！！！！！！！！！！！！！！！！！
    string convertToTitle(int n) {
        string result="";
        while(n>0){
            cout<<"n="<<n<<endl;
            char tmp = (n-1)%26+'A';
            result=tmp+result;
            n=(n-1)/26;
        }
        
        
        
        return result;
    }
};