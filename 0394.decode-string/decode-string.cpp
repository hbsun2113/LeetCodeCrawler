class Solution {
public:
    
    
    // 哈哈终于自己一下就做出来了，其实只要记住好while那一行就行！
    string decodeString(string s) {
        int i=0;
        return dfs3(s,i);
        
    }
    
    
    string dfs3(string &s, int &i){
        string res;
        while(i<s.size() && s[i]!=']'){
            if(isdigit(s[i])){
                int count=0;
                while(isdigit(s[i])){
                    count*=10;
                    count+=(s[i]-'0');
                    i++;
                }
                i++;
                string tmp=dfs3(s,i);
                i++;
                for(int k=0;k<count;k++) res+=tmp;
            }
            else{
                res+=s[i];
                i++;
            }    
        }
        return res;
    }
    
    
    // 二刷，没有做出来，做法太巧妙了！！
    // 这道题目的难点在于想到使用递归(其实s就是递归结构)：每当遇到数字，它所负责的[]中的内容都可以使用递归得到，而再后面的还是要继续拼接
    string decodeString2(string s) {
        int i=0;
        return dfs(s,i);
    }

    string dfs(string s, int &i){
        string res;
        while(i<s.size() && s[i]!=']'){  // 先记住while条件和if条件吧，感觉这题目好难
            if(!isdigit(s[i])) res+=s[i++];
            else{
                int count=0;
                while(isdigit(s[i])){
                    count*=10;
                    count+=(s[i]-'0');
                    i++;
                }
                i++;
                string tmp=dfs(s,i);
                i++;
                for(int c=0;c<count;c++) res+=tmp;
            }
        }
        return res;
    }











    //又没有做出来!!!!参考了：
    //https://leetcode.com/problems/decode-string/discuss/87543/0ms-simple-C++-solution
    string decodeString1(string s) {
       int i=0;
       return helper(s,i);
    }
    
    string helper(string &s, int &i){  //注意i是引用哦
        string result;
        while(i<s.size() && s[i]!=']'){
            if(!isdigit(s[i])){ 
                result+=s[i++]; //处理的是[]里的内容,它一定是由上层调用helper进入的。
            }
            else{//注意顺序，最先是数字，然后一定是[,再然后就是子串了。
                int n=0;
                while(i<s.size() && isdigit(s[i])){
                    n=10*n+(s[i++]-'0'); 
                }
                i++;//[
                string tmp=helper(s,i); 
                i++; //]
                while(n-- >0) result+=tmp;
            }
        }
        return result;
    }
};

