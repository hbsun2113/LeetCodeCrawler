class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;
        string res="";
        
        while(i>=0 && j>=0){
            int t=(a[i]-'0')+(b[j]-'0')+carry;
            res.push_back('0'+(t%2));
            carry=t/2;
            i--,j--;
        }
        
        while(i>=0){
            int t=(a[i]-'0')+carry;
            res.push_back('0'+(t%2));
            carry=t/2;
            i--;
        }
        
        while(j>=0){
            int t=(b[j]-'0')+carry;
            res.push_back('0'+(t%2));
            carry=t/2;
            j--;
        }

        if(carry==1) res.push_back('1');
        
        reverse(res.begin(),res.end());
        return res;
    }
};