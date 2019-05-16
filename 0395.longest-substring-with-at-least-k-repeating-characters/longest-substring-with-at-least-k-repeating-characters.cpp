class Solution {
public:
    //copy的：http://www.cnblogs.com/grandyang/p/5852352.html
    // i是遍历每个位置，我们以位置i为起点，去找符合条件的substr。
    // j表示该substr的末尾位置。
    // count记录当前该字符出现的个数。如果小于k，我们将mask相应位置置为1，表明还不够条件；否则置为0,表示这个字母的个数已经符合条件了。
    // 然后检查mask，如果mask==0,说明当前substr中所有字母都达到k了；否则还有不符合条件的字母。
    int longestSubstring1(string s, int k) {
        int result=0;
        int n=s.size();
        for(int i=0;i+k<=n;i++){
            vector<int> count(26,0);
            int mask=0;
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                count[idx]++;
                if(count[idx]<k) mask |= (1<<idx);
                else mask &= (~(1<<idx));
                if(mask==0){
                    result=max(result,j-i+1);
                }
            }
        }
        return result;
    }
    
    //我们进一步进行剪枝：max_end标记当前能达到的符合条件的substr的末尾，说明j+1位置的字符肯定不符合条件了，那么我们的i从j+1再开始。
    int longestSubstring(string s, int k) {
        int result=0;
        int n=s.size();
        int i=0;
        while(i+k<=n){
            vector<int> count(26,0);
            int mask=0;
            int max_end=i;
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                count[idx]++;
                if(count[idx]<k) mask |= (1<<idx);
                else mask &= (~(1<<idx));
                if(mask==0){
                    result=max(result,j-i+1);
                    max_end=j;
                }
            }
            i=max_end+1;
        }
        return result;
    }
    
    
    
};