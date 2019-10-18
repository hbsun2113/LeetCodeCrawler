class Solution {
public:
    // ?????????+??????
    void reverseWords(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
        
        i=0;
        while(i<s.size()){
            j=i;
            while(j+1<s.size() && s[j+1]!=' ') j++;
            int x=i,y=j;
            while(x<y){
                swap(s[x++],s[y--]);
            }
            i=j+2;
        }
    }
};