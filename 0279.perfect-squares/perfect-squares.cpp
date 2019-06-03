class Solution {
public:
    // https://www.acwing.com/solution/LeetCode/content/300/
    // 竟然自己没有做出来，想复杂了。
    // 对于每一个数n，去找所有比他小的平方数，然后看看它们如何组成n。
    int numSquares1(int n) {
        vector<int> vec(n+1,n);
        vec[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                vec[i]=min(vec[i],vec[i-j*j]+1);
            }
        }
        return vec[n];
    }
    
    
    // https://www.acwing.com/solution/LeetCode/content/300/ 中的解法二
    // 这个思路过于巧妙了
    // 第一个解法是前向搜索，这个是后向探索， 更符合我的初步思路。
    // 每拿到一个数，都看他可以组成哪些数字。
    // 这个解法可以用于拓展思路，不适合快速解题
    // 注意是搜索图不是搜索树
    int numSquares(int n) {
        vector<int> f(n + 1, n);
        queue<int> q;
        f[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int s = q.front();
            if (s == n)
                break;
            q.pop();
            for (int i = 1; s + i * i <= n; i++){
                if (f[s + i * i] > f[s] + 1) { // 看来BFS的思路是能不入队，就不入队，剪枝了
                    f[s + i * i] = f[s] + 1;
                    q.push(s + i * i);  // 只有自己更新了，才需要去更新后向的数， 才需要入队。
                }
            }
                
        }
        // cout<<"size="<<q.size()<<endl;
        return f[n];
    }

};