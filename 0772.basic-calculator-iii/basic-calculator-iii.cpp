class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/8873471.html
    // ??3????1.??? 2.???? 3.?op
    // ????? 1.???op 2.???num
    int calculate(string str) {
        if(str.size()==0) return 0;
        str+="+";
        int n=str.size();
        int res=0;
        char preop='+'; // ???????????????????????(op=='+' && preop=='+')
        int prenum=0;
        
        long long num=0; // ?????????long long 
        
        for(int i=0;i<n;i++){
            const auto &c=str[i];
            if(c==' ') continue;
            if(isdigit(c)){
                num*=10;
                num+=(c-'0');
            }
            else if(c=='('){
                int j=i+1;
                int cnt=0;
                for(;i<n;i++){
                    if(str[i]=='(') cnt++;
                    else if(str[i]==')') cnt--;
                    if(cnt==0) break;
                }
                num=calculate(str.substr(j,i-1-j+1));
            }
            else if(c=='+' || c=='-' || c=='*' || c=='/'){
                if(preop=='+')      prenum+=num;
                else if(preop=='-') prenum-=num;
                else if(preop=='*') prenum*=num;
                else if(preop=='/') prenum/=num;
                num=0;
                if(c=='+' || c=='-'){
                    res+=prenum;
                    prenum=0;
                }
                preop=c;
           }
        }
        
        return res;
    }
};