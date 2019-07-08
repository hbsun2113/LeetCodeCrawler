class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/6887140.html中的第一种解法
    // 1. 首先确定一个思想，要想让整体最大，那就局部都要最大，所以我们分别去看每个字符串，是原始的更大，还是反转的更大。选择更大的拼接到s上。
    // 2. 其实第一点有点不对，不是每个都要最大，只有一个例外，如果分割点在单词w，我们要想获得最大，w是否翻转不取决于对比w和reverse(w)。
    // 我们要分别遍历w、reverse(w)的每个位置，以寻找最优分割点
    // 3. 字符串mid是除了w以外其他的字符串拼接而成(最大)
    string splitLoopedString(vector<string>& strs) {
        string s;
        for(const auto &str:strs){
            string t(str.rbegin(),str.rend());
            s+= str>t?str:t;
        }
        cout<<s<<endl;
        
        int cur=0;
        string res;
        for(int i=0;i<strs.size();i++){
            
            string t1=strs[i];
            string t2=string(t1.rbegin(),t1.rend());
            
            string mid=s.substr(cur+t1.size())+s.substr(0,cur); 
            
            for(int j=1;j<=t1.size();j++){
                string w1=t1.substr(j)+mid+t1.substr(0,j);
                string w2=t2.substr(j)+mid+t2.substr(0,j);
                res=max(res,w1);
                res=max(res,w2);
            }
            
            cur+=t1.size();
        }
        
        return res;
    }
};