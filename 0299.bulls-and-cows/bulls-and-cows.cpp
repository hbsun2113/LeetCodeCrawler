class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> um;
        for(const auto &c:secret) um[c]++;
        
        int B=0;
        for(const auto &c:guess){
            if(um[c]!=0){
                B++;
                um[c]--;
            }
        }
        
        int A=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                A++;
                B--;
            }
        }
        
        string res=to_string(A)+"A"+to_string(B)+"B";
        return res;
    }
};