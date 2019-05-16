class Solution {
public:
    bool isPalindrome1(int x) {
        if(x<0) return false;
        string s=to_string(x);
        int len=s.size()-1;
        int i=0,j=len;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    
    //可以倒排，然后看是否相等。
    bool isPalindrome(int x) {
        if(x<0) return false;
        int sum=0;
        int xx=x;
        while(x>0)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        cout<<x<<" "<<sum<<endl;
        return sum==xx;
    }
};