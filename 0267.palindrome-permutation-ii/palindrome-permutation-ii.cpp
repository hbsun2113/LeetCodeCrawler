class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> um;
        for(const auto &c:s){
            if(um.find(c)!=um.end()) um.erase(c);
            else um[c]++;
        }
        return um.size()<=1;
    }
    
    unordered_set<string> res;
    unordered_map<char,int> um;
    vector<string> generatePalindromes(string s) {
        if(!canPermutePalindrome(s)) return {};
        for(const auto &c:s) um[c]++;
        int len=s.size();
        string tmp=string(len,' ');
        dfs(0,len-1,tmp);
        // for(auto &n:um){
        //     if(n.second>=2){
        //         tmp[0]=tmp[len-1]=n.first;
        //         n.second-=2;
        //         dfs(0+1,len-1-1,tmp);
        //         n.second+=2;
        //     }
        // }
        return vector<string>(res.begin(),res.end());
    }
    
    void dfs(int l, int r, string tmp){
        // cout<<l<<" "<<r<<" "<<tmp<<endl;
        if(l>=r){
            for(const auto n:um){
                if(n.second==1){
                    tmp[l]=n.first;
                    break;
                }
            }
            res.insert(tmp);
            return ;
        }
        for(auto &n:um){
            if(n.second>=2){
                tmp[l]=tmp[r]=n.first;
                n.second-=2;
                dfs(l+1,r-1,tmp);
                n.second+=2;
            }
        }
    }
};