class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char,pair<int,int>> um;
        int i=0;
        for(char c='a';c<='e';c++){
            um[c].first=0;
            um[c].second=i++;
        }
        
        i=0;
        for(char c='f';c<='j';c++){
            um[c].first=1;
            um[c].second=i++;
        }
        
        i=0;
        for(char c='k';c<='o';c++){
            um[c].first=2;
            um[c].second=i++;
        }
        
        i=0;
        for(char c='p';c<='t';c++){
            um[c].first=3;
            um[c].second=i++;
        }
        
        i=0;
        for(char c='u';c<='y';c++){
            um[c].first=4;
            um[c].second=i++;
        }
        
        um['z'].first=5;
        um['z'].second=0;
        
        char c='a';
        string res="";
        for(const auto w:target){
            int x=abs(um[c].first-um[w].first);
            int y=abs(um[c].second-um[w].second);
            char a,b;
            if(um[c].first<um[w].first) a='D';
            else a='U';
            if(um[c].second<um[w].second) b='R';
            else b='L';
            if(c=='z'){
                res+=string(x,a);
                res+=string(y,b);
            }
            else{
                res+=string(y,b);
                res+=string(x,a);
            }
            res+="!";
            c=w;
        }
        
        return res;
    }
};