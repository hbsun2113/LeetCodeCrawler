class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        for(int i=0;i<m && i<n;i++){// 如果有答案，则一个字符串必然为另一个字符串的一部分
            if(str1[i]!=str2[i]) return "";
        }
        int gc=gcd(m,n);
        string res="";
        for(int i=0;i<gc;i++) res+=str1[i];
        return res;
    }
        
    
    // 自己做的
    string gcdOfStrings1(string str1, string str2) {
        if(str1==str2) return str1;
        if(str1.size()>str2.size()) swap(str1,str2);
        int res=0;
        string ress="";
        int len1=str1.size(),len2=str2.size();
        for(int i=1;i<=str1.size();i++){
            string tmp=str1.substr(0,i);
            int len3=tmp.size();
            string concen="";
            while(concen.size()<str2.size())
                concen+=tmp;
            if(concen==str2){
                // cout<<str1<<" "<<str2<<" "<<tmp<<" "<<concen<<endl;
                // cout<<str1.size()<<" "<<str2.size()<<" "<<tmp.size()<<" "<<concen.size()<<endl;
                if((str1.size()%tmp.size())!=0) continue;
                if((int)tmp.size()>res){
                   res=tmp.size();
                   ress=tmp;
                }
            } 
        }
        return ress;
    }
};