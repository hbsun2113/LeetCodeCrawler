class Solution {
public:
    // 二刷
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        for(int j=0;j<s.size();j++){
            if(s[j]>=g[i]) i++;
            if(i==g.size()) return g.size();
        }
        return i;
    }
    
    // 从小到大遍历s，看看是否可以满足当前的g,如果可以则结果加一，并且g也向后移动。否则只单纯移动s,直到找到能满足条件的s。
    // g中小需求尽可能地使用s中小饼干满足，因此是对s从小到大遍历。
    int findContentChildren1(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int res=0;
        for(int j=0;j<s.size();j++){
            if(g[i]<=s[j]){
                res++;
                i++;
                if(i==g.size()) return res;
            }
        }
        return res;
    }


    // 从后往前遍历
    // 我想的是充分发挥s中大饼干的作用，尽可能地把它分配给g中需求大的孩子。但是这么做做麻烦了。
    int findContentChildren2(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0;
        int j=g.size();
        for(int i=s.size()-1;i>=0;i--){
            auto it = upper_bound(g.begin(),g.begin()+j,s[i]);
            it--;
            if(it>=g.begin()) res++;
            // else return res; // 剪枝：说明s连当前g中最小的需求都无法满足了，因此直接返回结果就行。
            j = distance(g.begin(),it);
        }
        return res;
    }
};

