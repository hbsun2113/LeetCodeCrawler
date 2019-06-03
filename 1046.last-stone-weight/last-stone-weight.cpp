class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(const auto &s:stones){
            p.push(s);
        }
        while(p.size()>=2){
            auto t1=p.top();
            p.pop();
            auto t2=p.top();
            p.pop();
            if(t1>t2) swap(t1,t2);
            if(t2>t1) p.push(t2-t1);
        }
        if(p.size()==1) return p.top();
        return 0;
    }
};