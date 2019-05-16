class Solution {
public:
    string addBinary(string a, string b) {
        int len1=a.size();
        int len2=b.size();
        int carry=0;
        string res="";
        int i=len1-1,j=len2-1;
        while(i>=0 && j>=0){
            int ca=a[i--]-'0';
            int cb=b[j--]-'0';
            int curr=(ca+cb+carry)%2;
            carry=(ca+cb+carry)/2;
            res=to_string(curr)+res;
        }
        while(i>=0){
            int ca=a[i--]-'0';
            int curr=(ca+carry)%2;
            carry=(ca+carry)/2;
            res=to_string(curr)+res;
        }
        while(j>=0){
            int cb=b[j--]-'0';
            int curr=(cb+carry)%2;
            carry=(cb+carry)/2;
            res=to_string(curr)+res;
        }
        if(carry==1)
            res=to_string(carry)+res;
        return res;
    }
};