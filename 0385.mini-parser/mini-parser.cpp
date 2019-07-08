class Solution {
public:
    // https://www.cnblogs.com/grandyang/p/5771434.html
    // 这道题目的精髓在于cnt，它指示了什么时候能拿到一个完整的元素
    NestedInteger deserialize(string s) {
        cout<<s<<endl;
        if(s.size()==0) return NestedInteger(); 
        if(s[0]!='[') return NestedInteger(stoi(s));
        if(s.size()==2) return NestedInteger(); // 对应这种情况 []
        
        NestedInteger res;
        int cnt=0,start=1;
        for(int i=1;i<s.size();i++){
            if(cnt==0 && (s[i]==',' || i==s.size()-1)){
                res.add(deserialize(s.substr(start,i-start)));
                start=i+1;
                continue;
            }
            if(s[i]=='[') cnt++; // 注意和前面if的顺序。仔细想想，肯定是放到后面更合适。比如[[1,2,3],[0]]。如果想获得完整的[1,2,3]，肯定是[]使得cnt为0了，然后遇到了","，我们才可以获得[1,2,3]。
            else if(s[i]==']') cnt--;
        }
        
        return res;
    }
    
};
