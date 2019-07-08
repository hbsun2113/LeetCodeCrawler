class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/4350381.html 的思想
    // https://leetcode.com/problems/text-justification/discuss/24873/Share-my-concise-c++-solution-less-than-20-lines 中 @rpfly3的回答
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        int cur_width=0;
        int j;
        for(int i=0;i<n;i=j){
            
            for(j=i,cur_width=0;j<n && cur_width+words[j].size()+j-i<=maxWidth;j++)
                cur_width+=words[j].size();
            
            // 这是为了最后一行准备的默认值
            int space=1;
            int extra=0;
            
            if(j-1!=i && j!=words.size()){
                space=(maxWidth-cur_width)/(j-i-1); // j-i-1 是空的数目，space是空的大小
                extra=(maxWidth-cur_width)%(j-i-1);
            }
            // cout<<words[i]<<" "<<words[j-1]<<" "<<space<<" "<<extra<<endl;
            
            string line="";
            for(int k=i;k<j;k++){
                line+=words[k];
                if(k!=j-1) line+=string(space, ' ');
                if(extra-->0) line+=' ';
            }
            line += string(maxWidth - line.size(), ' ');
            res.push_back(line);
        }
        return res;
    }
};