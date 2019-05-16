class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int l=0,r=0;
        int i=0;
        string tmp;
        while(i<S.size()){
            tmp+=S[i];
            if(S[i]=='(') l++;
            else r++;
            i++;
            if(l==r){
                // cout<<"tmp="<<tmp<<endl;
                res+=(tmp.substr(1,tmp.size()-2));
                tmp="";
                l=0,r=0;
            }
            
        }
        return res;
    }
};