class Solution {
public:
    
    
    // 自己写的，非常低效
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>3*4 || s.size()<1*4) return res;
        dfs(s,"",0);
        return res;
    }
    
    void dfs(string &s, string tmp, int start){
        if(start==s.size() && tmp.size()==s.size()+4){
            tmp.pop_back();
            res.push_back(tmp);
            return ;
        }
        if(start==s.size()) return ;
        for(int l=1;l<=3;l++){
            if(start+l-1==s.size()) return ;
            string first=s.substr(start,l);
            if(!check(first)) continue;
            dfs(s,tmp+first+".",start+l);
        }
    }
    
    // 这次check踩了个坑： string s1="35", s2="255"; 则 s1>s2 会返回true！ 因为string是按位比较的,所以要先转换为int
    // 自己在stackoverflow上提的问题也很好：https://stackoverflow.com/questions/56354700/how-to-compare-the-temporary-variables-in-the-form-of-string，字符串常量的比较结果是不确定的，因为他们比较的是地址！！
    /*
         cout<<("35"<"255")<<" "; // 1
         cout<<("35"<"955")<<" "; // 1
         cout<<("255"<"955")<<" "; // 1
    */
    bool check(string s){
        if(s.size()!=1 && s[0]=='0') return false; // 不应该有前缀0
        if(stoi(s)>255) return false;
        return true;
    }
    
    
    
    
    //https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
    //简单的，推荐写法！
    vector<string> restoreIpAddresses3(string s) {
        vector<string> res;
        for(int a=1;a<=3;a++)
        for(int b=1;b<=3;b++)
        for(int c=1;c<=3;c++)
        for(int d=1;d<=3;d++){
            // 这行可别忘了！否则会产生重复值。
            // 因为对substr来说，如果len大于字符串长度，也不会报错。
            if(a+b+c+d!=s.size()) continue;

            int A=stoi(s.substr(0,a));
            int B=stoi(s.substr(a,b));
            int C=stoi(s.substr(a+b,c));
            int D=stoi(s.substr(a+b+c,d));
            if(A>255 || B>255 || C>255 || D>255) continue;
            string tmp=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
            if(tmp.size()==s.size()+3){ // 这个避免了前导0的出现
                // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" | ";
                res.push_back(tmp);
            }
        }
        return res;
    }

    
    //标准dfs做法
    vector<string> restoreIpAddresses2(string s) {
        vector<string> result;
        string tmp("");
        helper(s,result,tmp,0,0);
        return result;
    }
    
    void helper(string s, vector<string> &result, string tmp, int index, int count){
        if(count>4) return ;
        if(index==s.size() && count==4) result.push_back(tmp);
        for(int i=1;i<=3;i++){
            if(index+i>s.size()) return;
            string part=s.substr(index,i);
            if(isvalid(part)){
                //cout<<part<<endl;
                if(count!=3) part+="."; 
                helper(s,result,tmp+part,index+i,count+1);
            }
                
        }
        
    }
    
    bool isvalid(string s){
        if(s.size()==0) return false;
        if(s.size()>1 && s[0]=='0') return false;
        int num=0;
        for(int i=0;i<s.size();i++){
            num*=10;
            num+=(s[i]-'0');
        }
        if(num<=255) return true;
        return false;
    }
    
    
    
    
};

