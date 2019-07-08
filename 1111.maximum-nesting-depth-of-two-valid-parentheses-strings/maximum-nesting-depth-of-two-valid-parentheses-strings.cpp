#define dbv(v) cout << #v << "="; for (auto _x : v) cout << _x << ", "; cout << endl
class Solution {
public:
    // 其实我们要做的就是要尽量保证A和B的深度相等
    // 代码中A和B分别代表各自的开括号(还没有对应的闭括号)的数量
    // https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/discuss/328841/JavaC%2B%2BPython-Several-Ideas/301774
    vector<int> maxDepthAfterSplit1(string s) {
        int n=s.size();
        int A=0,B=0;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            auto &c=s[i];
            if(c=='('){
                if(A<B) A++;
                else {
                    B++;
                    res[i]=1;
                }
            }
            else {
                if(A>B) A--;
                else {
                    B--;
                    res[i]=1;
                }
            }
        }
        return res;
    }
    
    // 这个解法暂时没有看懂
    // https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/discuss/329318/Can-someone-explain-the-code-of-neal_wu/302040
    /*
    ( ) ( ( ) ) ( )
  0 1 0 1 2 1 0 1 0
    [1,1,1,0,0,1,1,1]
    [0,1,0,0,0,1,0,1]
    */
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> levels(n + 1, 0);

        for (int i = 0; i < n; i++)  // levels[i]描述的是seq[i-1]的状态
            levels[i + 1] = levels[i] + (seq[i] == '(' ? +1 : -1);
        dbv(levels);
        
        int max_level = *max_element(levels.begin(), levels.end());
        int half = max_level / 2;
        vector<int> answer(n, 0);
        cout<<half<<endl;

        
        for (int i = 0; i < n; i++){
            // answer[i] = levels[i+1] < half ? 1 : 0;
            answer[i] = min(levels[i], levels[i + 1]) < half ? 1 : 0;
            cout<<i<<" "<<min(levels[i], levels[i + 1]) <<" "<<levels[i]<<" " <<levels[i + 1]<<endl;
        }
        
        // 错误的：
        // for (int i = 1; i <= n; i++){
        //     answer[i-1] = levels[i] < half ? 1 : 0;
        // }
            
            

        return answer;
    }
};