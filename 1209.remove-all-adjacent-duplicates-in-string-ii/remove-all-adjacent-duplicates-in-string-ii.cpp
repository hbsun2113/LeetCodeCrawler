class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int cnt=0;
        for(const auto &c:s){
            if(!st.empty() && c==st.top().first){
                st.push({c,st.top().second+1});
            }
            else 
                st.push({c,1});
            if(st.top().second==k){
                for(int j=0;j<k;j++)
                    st.pop();
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};