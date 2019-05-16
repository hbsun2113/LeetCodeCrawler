class Solution {
public:
    // 这个好难想，花了很久的时间也没觉得想明白了
    // 这道题目是求最长。j每次都前进一步，而i是能不前进就不前进，这样才能保证捕获到最长字符串。
    // 因此在res=max(res,j-i+1);时，窗口可能是无效的，但是并不影响res，因为这时[i,j]顶多和之前最大的res持平，不会去更新res。
    // 只有在拿到新字符的时候，res才可能被变大。
    
    // 有助思考：我们要么扩展右边界，要么是将窗口整个向右移动。
    
    
    
    int characterReplacement(string s, int k) {
        if(s.size()==0) return 0;
        unordered_map<char,int> um;
        int count=0;
        int res=1;
        for(int i=0,j=0;j<s.size();j++){
            um[s[j]]++;
            count=max(count,um[s[j]]);
            if(j-i+1-k>count){  // 这里使用if就好了，没有必要使用while。从这里就可以初见解题思路
                um[s[i++]]--;
            }
            
            if(res<j-i+1){  //理解之用：if(res<=j-i+1){ 
                // cout<<s.substr(i,j-i+1)<<endl;
                res=j-i+1;
            }
        }
        return res;
    }
};