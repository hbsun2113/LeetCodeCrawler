const int LETTERS = 26;

class Solution {
public:
    // ??tiankonguse?????
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> freq(1<<26,0);
        for(const auto &s:words){  // ????word?????
            int bit=0;
            for(const auto &c:s)
                bit |= (1<<(c-'a'));
            freq[bit]++;
        }
        
        vector<int> res(puzzles.size());
        for(int i=0;i<puzzles.size();i++){
            const auto &p=puzzles[i];
            int bit=0;
            for(const auto &c:p)
                bit |= (1<<(c-'a'));
            
            int cur=bit; // ??[0,bit]???????????????????????????word????????
            int first=1<<(p[0]-'a');
            while(cur!=0){
                if(cur & first) res[i]+=freq[cur];
                
                if(cur==0) break;
                
                cur=(cur-1)&bit; // ?????????????????1
            }
        }
        
        return res;
    }
        
};