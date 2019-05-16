typedef long long ll;
class Solution {
public:
    // 题目倒是不难，但是边界条件可是要考虑清楚呀~
    // 更清晰的写法：https://leetcode.com/problems/add-strings/discuss/90453/C++_Accepted_13ms
    string addStrings(string num1, string num2) {
        if(num1.size()==1 && num2.size()==1 && ((num1.back()-'0')+(num2.back()-'0')==0)) return "0";
        string res="";
        int flag=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 && j>=0){
            int tmp=(num1[i]-'0')+(num2[j]-'0')+flag;
            int curr=tmp%10;
            flag=tmp/10;
            res.insert(res.begin(),curr+'0');
            i--,j--;
        }
        while(i>=0){
            int tmp=(num1[i]-'0')+flag;
            int curr=tmp%10;
            flag=tmp/10;
            res.insert(res.begin(),curr+'0');
            i--;
        }
        while(j>=0){
            int tmp=(num2[j]-'0')+flag;
            int curr=tmp%10;
            flag=tmp/10;
            res.insert(res.begin(),curr+'0');
            j--;
        }
        if(flag==1)
            res.insert(res.begin(),'1');
        return res;
    }
    
    
};