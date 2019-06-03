class Solution {
public:
    
    bool canTransform(string s, string e) {
        // count
        int sumrs,sumre;
        int sumls,sumle;
        sumrs=sumre=sumls=sumle=0;
        
        // position
        vector<char> vs,ve;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                sumrs++;
                vs.push_back(s[i]);
            }
            else if(s[i]=='L'){
                sumls++;
                vs.push_back(s[i]);
            }
            
            if(e[i]=='R'){
                sumre++;
                ve.push_back(e[i]);
            }
            else if(e[i]=='L'){
                sumle++;
                ve.push_back(e[i]);
            }
            
            if(sumrs<sumre) return false; // 因为r是向右移动：s中r的数量 不可以 少于 e中r的数量
            if(sumls>sumle) return false;
            
        }
        if(sumrs!=sumre) return false;
        if(sumls!=sumle) return false;
        if(vs!=ve) return false;
        
        return true;
    }
    
    
    
    
    // bruce force TLE
    unordered_map<string,bool> um;
    bool canTransform1(string start, string end) {
        if(um.count(start)) return um[start];
        if(start==end){
            um[start]=true;
            return um[start];
        } 
        um[end]=true;
        int n=start.size();
        string tmp;
        um[start]=true;
        for(int i=0;i+1<n;i++){
            tmp=start;
            if(tmp[i]=='X' && tmp[i+1]=='L'){
                swap(tmp[i],tmp[i+1]);
                if(canTransform(tmp,end)) return true;
            }
            else if(tmp[i]=='R' && tmp[i+1]=='X'){
                swap(tmp[i],tmp[i+1]);
                if(canTransform(tmp,end)) return true;
            }
        }
        um[start]=false;
        return false;
    }
};