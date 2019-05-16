class Solution {
public:
    int myAtoi(string str) {
        // str=" 01234";
        // cout<<str[0]<<endl;
        string s;
        int index=0;
        int flag=1;
        int zero=1000;
        int space=0;
        int positive=0,negative=0,pp=1000,np=1000;
        while(((str[index]=='+' || str[index]=='-') || (str[index]==' ' || str[index]=='0' )) && index<str.size()){
            if(str[index]=='+'){
                positive++;
                pp=index;
            }
            else if(str[index]=='-'){
                negative++;
                np=index;
            }
            else if(str[index]=='0') zero=index;
            else if(str[index]==' ') space=index;
            index++;
        }
        if(zero<space || np<space || pp<space) return 0;
        if(positive+negative>1) return 0;
        if(negative%2==0) flag=1;
        else flag=-1;
        int len=0;
        while(str[len+index]>='0' && str[len+index]<='9'){
            //cout<<index<<" "<<index+len<<" "<<str[index+len]<<endl;
            len++;
        }
        s=str.substr(index,len);
        cout<<s<<endl;
        long result=0;
        long base=1;
        for(int i=s.size()-1;i>=0;i--){
            cout<<base*(s[i]-'0')<<" ";
            result+=base*(s[i]-'0');
            cout<<result<<endl;
            base*=10;
            if(result*flag >= INT_MAX) return INT_MAX;
            if(result*flag <= INT_MIN) return INT_MIN;
        }
        result*=flag;
        
        
        
        return result;
        
    }
};