class Solution {
public:
    // 三刷做出来了,主要思路就是在插入当前元素的时候，要确保之前的元素已经被插入进去了
    // 注意以后为了避免出错，cmp函数一定不要直接返回true或者false，而是去返回比较结果，或者像三刷这么写
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        auto cmp=[](vector<int> &a, vector<int> &b){
            if(a[0]!=b[0]) return a[0]>b[0];  
            else return a[1]<b[1];
        };
        
        /*比较函数的错误写法示例：
        auto cmp=[](vector<int> &a, vector<int> &b){
            if(a[0]>b[0]) return true;  
            else return a[1]<b[1];
        };*/
        
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<people.size();i++){
            cout<<people[i][0]<<" "<<people[i][1]<<endl; // 打印出来，以便理解
            res.insert(res.begin()+people[i][1],people[i]);
        }
        return res;
    }
    
    // 二刷没有做出来
    // 对于其中一个高度来说，比他高并且second比它小的元素一定是排在他前面的，因此从大到小排序，这样在插入的时候可以保证前面的个数是足够的。
    vector<pair<int, int>> reconstructQueue2(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        auto cmp=[](pair<int,int> &a,pair<int,int> &b){
            return (a.first>b.first) || (a.first==b.first && a.second<b.second);
        };
        sort(people.begin(),people.end(),cmp);
        for(const auto p:people){
            res.insert(res.begin()+p.second,p);
        }
        return res;
    }
};