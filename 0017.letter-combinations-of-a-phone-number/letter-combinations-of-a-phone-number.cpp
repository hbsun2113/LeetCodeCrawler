class Solution {
public:
    vector<string> result;
    unordered_map<char,vector<char>> um;
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return result;
        um['2']=vector<char>({'a','b','c'});
        um['3']=vector<char>({'d','e','f'});
        um['4']=vector<char>({'g','h','i'});
        um['5']=vector<char>({'j','k','l'});
        um['6']=vector<char>({'m','n','o'});
        um['7']=vector<char>({'p','q','r','s'});
        um['8']=vector<char>({'t','u','v'});
        um['9']=vector<char>({'w','x','y','z'});
        string curr="";
        helper(digits,curr,0);
        return result;
    }
    
    void helper(string &digits, string curr, int index){
        if(index==digits.size()){
            result.push_back(curr); 
            return ;
        }
        char c=digits[index];
        vector<char> &tmp=um[c];
        for(const auto& t:tmp){
            helper(digits,curr+t,index+1);
        }
    }
};