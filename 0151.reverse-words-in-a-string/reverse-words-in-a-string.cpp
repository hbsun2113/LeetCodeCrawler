class Solution {
public:
     string reverseWords(string s) {
         istringstream ins(s);
         s="";
         string tmp;
         while(ins>>tmp){
             reverse(tmp.begin(),tmp.end());
             s+=tmp;
             s+=" ";
         }
         
         if(!s.empty()){
             s.pop_back();
             reverse(s.begin(),s.end());
         }
         
         return s;
     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //inplace做法：1.先按顺序找到要处理的字符串并且把它放到合适的位置(没有多余的空格) 
    // 2. 然后将该字符串翻转
    // 3. 将整个字符串翻转
    //https://www.acwing.com/solution/LeetCode/content/245/
    //https://leetcode.com/problems/reverse-words-in-a-string/discuss/47840/C++-solution-in-place:-runtime-O(n)-memory-O(1)里的讨论
    string reverseWords2(string s) {
        int i=0; //i是遍历的索引。
        int j=0; //j是新串的索引，就是为了去除多余的空格，把后面的字符串直接放到j的位置。
        while(true){
            while(i<s.size() && s[i]==' ') i++;  //去除前导空格
            if(i>=s.size()) break;
            if(j!=0) s[j++]=' ';
            int start=j; 
            while(i<s.size() && s[i]!=' ')
                s[j++]=s[i++];
            
            reverse(s.begin()+start,s.begin()+j); 
        }
        s.resize(j);
        reverse(s.begin(),s.end());
        return s;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    //自己做的暴力解法，需要空间。
    string reverseWords1(string s) {
        vector<string> vec;
        int i=0;
        string tmp="";
        while(i<s.size()){
            if(s[i]==' '){
                if(tmp==""){
                    i++;
                    continue;
                }
                vec.push_back(tmp);
                tmp="";
            }
            else{
                tmp+=s[i];
            }
            i++;
        }
        if(tmp.size()!=0) vec.push_back(tmp);
        string res;
        for(int i=vec.size()-1;i>=0;i--){
            if(i==0) res+=vec[i];
            else res+=(vec[i]+" ");
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    //使用istringstream，避免了处理空格的麻烦。
    //https://leetcode.com/problems/reverse-words-in-a-string/discuss/47777/5-lines-C++-using-lessstringstreamgreater
    string reverseWords3(string s) {
        istringstream ins(s);  //读入数据
        s="";
        string word;
        while(ins>>word){ //每次输出一个无空格的数据
            reverse(word.begin(),word.end());
            word+=" ";
            s+=word;
        }
        if(!s.empty()){
            s.pop_back();
            reverse(s.begin(),s.end());
        }
        return s;
    }
};