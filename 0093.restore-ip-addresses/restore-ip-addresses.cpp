/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (30.92%)
 * Total Accepted:    133.5K
 * Total Submissions: 431K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    //https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
    //简单粗暴
    vector<string> restoreIpAddresses(string s) {
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
            if(tmp.size()==s.size()+3){
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" | ";
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

