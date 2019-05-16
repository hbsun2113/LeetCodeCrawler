class Solution {
public:
    //自己做的，思路如下：
    // 首先观察！
    // 如果s里本身有回文，那么一定是从s的起始点就开始的，这样才能使最终结果最小。
    // 那我们就从后往前搜索，看看要前进多少步，s的前半部分才能构成一个回文串。 
    // 然后我们在s的前面添加字符，使得它们可以和s的后半部分(非回文部分)向呼应上。
    string shortestPalindrome(string s) {
        for(int j=s.size()-1;j>=0;j--){
            if(ispalindrome(s, j)){
                string tmp=s.substr(j+1);
                reverse(tmp.begin(),tmp.end());
                s.insert(0,tmp);
                return s;
            }
        }
        string tmp=s;
        tmp.reserve();
        return tmp+s;
    }
    
    bool ispalindrome(string s, int j){
        int i=0;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};