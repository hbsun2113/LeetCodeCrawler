class Solution {
public:
    // 这道题目的确挺难，好在现在理解了，并且仍然可以使用模板解(https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems?orderBy=most_votes)
    
    // 这道题目关键在于比模板多一个for循环：for(int i=0;i<len;i++)。原因可以参见：https://leetcode.windliang.cc/leetCode-30-Substring-with-Concatenation-of-All-Words.html。分组的思想，这样我们就可以对start和end每次按照步长len进行更新。这个方法要记住！
    // start和end按照len进行更新的必要性：我们要处理的是单词，否则会出现重叠现象无法判断
    // 
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0) return res;
        int len=words[0].size();
        unordered_map<string,int> ori_um; 
        for(const auto w:words) ori_um[w]+=1;
        
        for(int i=0;i<len;i++){
            auto um=ori_um;
            int start=i; // 窗口还是window=[start,end],我们要检查的是window是否符合条件
            int count=words.size(); // 需要的数量
            
            // 模板
            for(int end=i+len-1;end<s.size();end+=len){
                if(um[s.substr(end-len+1,len)]-->=1) count--;
                // cout<<start<<" "<<end<<" "<<s.substr(start,end-start+1)<<" "<<count<<endl;
                while(count==0){
                    if(end-start+1==len*words.size()) res.push_back(start);
                    if(um[s.substr(start,len)]++>=0) count++;
                    start+=len;
                }
            }
            
        }
        
        return res;
    }
};


