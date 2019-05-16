class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int count=0;
        int line=0;
        for(const auto &c:S){
            count+=widths[c-'a'];
            if(count>100){
                line++;
                count=0;
                count+=widths[c-'a'];
            }
            else if(count==100){
                count=0;
                line++;
            }
        }
        if(count!=0) line++;
        vector<int> result;
        result.emplace_back(line);
        result.emplace_back(count);
        return result;
        
        
    }
};