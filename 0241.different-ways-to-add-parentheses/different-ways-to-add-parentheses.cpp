class Solution {
public:
    // https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66328/A-recursive-Java-solution-(284-ms)
    // The key idea for this solution is: each operator in this string could be the last operator to be operated. We just iterator over all these cases
    unordered_map<string,vector<int>> um;
    vector<int> diffWaysToCompute(string input) {
        if(um.find(input)!=um.end()) return um[input];
        vector<int> res;
        for(int i=0;i<input.size();i++){
            if(input[i]=='+' || input[i]=='-' || input[i]=='*'){
                auto l=diffWaysToCompute(input.substr(0,i));
                auto r=diffWaysToCompute(input.substr(i+1));
                for(auto x:l){
                    for(auto y:r){
                        switch(input[i]){
                            case('+'):
                                res.push_back(x+y);
                                break;
                            case('-'):
                                res.push_back(x-y);
                                break;
                            case('*'):
                                res.push_back(x*y);
                                break; 
                        }
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input)); // ??????????????
        um[input]=res;
        return res;
    }
};