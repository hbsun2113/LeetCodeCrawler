class Worker{
public:
    double w2q;
    int quality,wage;
    int id;
    Worker(int _id, int _quality, int _wage, double _w2q):id(_id),quality(_quality),wage(_wage),w2q(_w2q){}
};

class Solution {
public:
    // 一刷：
    // 部分参考了https://www.acwing.com/solution/LeetCode/content/570/
    // 首先确定base:将数组按w2q排序，如果当前元素为base,则其左边一定满足要求2
    // 因此只要从左面选择质量最小的K-1个元素，乘上w2q就可以了。 使用优先队列维护最小的K个。
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res=INT_MAX;
        
        vector<Worker> vec;
        for(int i=0;i<quality.size();i++){
            vec.emplace_back( i, quality[i], wage[i], double(wage[i])/double(quality[i]) );
        }
        
        auto cmp=[](Worker &a, Worker &b){
            return a.w2q<b.w2q;
        };
        sort(vec.begin(),vec.end(),cmp);
        
        priority_queue<int> p;
        int sum=0; // 队列中元素总和
        for(int i=0;i<vec.size();i++){
            p.push(vec[i].quality);
            sum+=vec[i].quality;
            if(p.size()<K) continue;
            if(p.size()>K){ // 只要超过K个，就把其中最大的删掉
                sum-=p.top();
                p.pop();
            }
            res=min(res,sum*vec[i].w2q);
        }
        
        return res;
    }
};