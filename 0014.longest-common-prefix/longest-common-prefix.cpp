class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        string s=strs[0];
        int index;
        for(int i=1;i<strs.size();i++){
            index=0;
            while(index<strs[i].size() && s[index]==strs[i][index]) index++;
            s=strs[i].substr(0,index);
        }
        return s;
        
    }
};