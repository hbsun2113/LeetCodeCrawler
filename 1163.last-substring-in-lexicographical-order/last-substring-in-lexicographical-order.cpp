class Solution {
public:
    string lastSubstring(string s) {
        if(s.size()==0) return s;
        char t='a';
        vector<int> vec;
        for(const auto &c:s)
            t=max(t,c);
        for(int i=0;i<s.size();i++){
            if(s[i]==t) vec.push_back(i);
        }
        if(vec.size()==s.size()) return s;
        // cout<<t<<" "<<vec.size()<<endl;
        
        int len=2;
        while(vec.size()!=1){
            // cout<<t<<" "<<vec.size()<<endl;
            vector<int> tmp;
            t='a';
            for(auto &i:vec){
                if(i+len-1<s.size()) t=max(t,s[i+len-1]);  
            }
            for(auto &i:vec){
                if(i+len-1<s.size() && t==s[i+len-1]) tmp.push_back(i);
            }
            vec=move(tmp);
            len++;
        }
        
        return s.substr(vec[0],s.size()-1-vec[0]+1);
    }
};