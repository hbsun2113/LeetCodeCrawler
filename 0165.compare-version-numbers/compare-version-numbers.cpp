class Solution {
public:
    
    
    
    
    //https://leetcode.com/problems/compare-version-numbers/discuss/50767/My-2ms-easy-solution-with-CC++ 这个解法也很好
    
    
    
    
    
    
    
    
    
    
    
    
    
    //自己做的。先把字符串分割使用vec保存，其中长度小的vec填入等长度的“0”。 然后拿出来比较。
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        remove_dot(version1,v1);
        remove_dot(version2,v2);
        fill_0(v1,v2);
        int index=0;
        while(index<v1.size()){
            int a=stoi(v1[index]);
            int b=stoi(v2[index]);
            if(a<b) return -1;
            if(a>b) return 1;
            
            index++;
        }
        return 0;
        
        
    }
    
    
    void fill_0(vector<string>& v1, vector<string>& v2){
        if(v1.size()==v2.size()) return ;
        vector<string> *a=&v1,*b=&v2;  //注意不可以使用引用，这里只能使用指针。
        if(v1.size()>v2.size()){
            a=&v2,b=&v1;
        }
        int len=b->size()-a->size();
        while(--len>=0){
            a->push_back("0");
        }
    }
    
    
    
    void remove_dot(string s, vector<string>& vec){
        string tmp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                if(tmp.size()!=0)
                    vec.push_back(tmp);
                tmp="";
            }
            else
                tmp+=s[i];
        }
        if(tmp.size()!=0) vec.push_back(tmp);
    }
};