class Solution {
public:
    //比较麻烦，也不能算是自己做的，主要参考了这个：https://www.cnblogs.com/springfor/p/3889706.html
    string multiply1(string num1, string num2) {
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int length1=num1.size(),length2=num2.size();
        int carry=0;
        string result="";
        vector<int> r(length1+length2,0);
        for(int i=0;i<length1;i++){
            for(int j=0;j<length2;j++){
                r[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                cout<<r[i+j]<<endl;
            }
        }
        for(int i=0;i<length1+length2;i++){
            int digit=r[i]%10;
            carry=r[i]/10;
            result.insert(result.begin()+0,digit+'0');
            if(i<length1+length2-1) r[i+1]+=carry;
        }
        cout<<result<<endl;
        for(int i=0;i<length1+length2;i++){
            if(result[i]!='0'){
                // cout<<"i:"<<i<<":"<<result[i]<<endl;
                result=result.substr(i,length1+length2-i);
                break;
            }
            if(i==length1+length2-1) return "0";
        }
        return result;
        
    }
    
    
    
    string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }
    
    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}
};