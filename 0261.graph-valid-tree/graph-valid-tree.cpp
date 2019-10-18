class Solution {
 public:
  struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = 0) {
      if (n > 0)
        init(n);
    }

    void init(int n) {
      parent.resize(n + 1);
      size.assign(n + 1, 1);
      components = n;

      for (int i = 0; i <= n; i++)
        parent[i] = i;
    }

    int find(int x) {
      return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
      x = find(x);
      y = find(y);

      if (x == y)
        return false;

      if (size[x] < size[y])
        swap(x, y);

      parent[y] = x;
      size[x] += size[y];
      components--;
      return true;
    }
  };
    // ???neal_wu?union_find??
  bool validTree1(int n, vector<vector<int>> &edges) {
    if (n == 0) return true;
    union_find un(n);
    for (auto &v:edges) {
      if (!un.unite(v[0], v[1])) return false;
    }
    return un.components==1;
  }
    
    
  // https://leetcode.com/problems/graph-valid-tree/discuss/69018/AC-Java-Union-Find-solution
  // https://leetcode.com/problems/graph-valid-tree/discuss/69019/Simple-and-clean-c++-solution-with-detailed-explanation.
  // ??????union_find??????????
  // 1. ????
  // 2. ????????????n?????n-1??    
  vector<int> parent;  
  bool validTree(int n, vector<vector<int>> &edges) {
    if (n == 0) return true;
    if (edges.size() != n-1) return false; // ?????????????
    for(int i=0;i<n;i++)
        parent.push_back(i);
    for(auto &v:edges){
        int x=find(v[0]);
        int y=find(v[1]);
        if(x==y) return false; // ??????
        parent[x]=y;
    }
    return true;
  }  
  
  int find(int x){
      if(parent[x]==x) return x;
      parent[x]=find(parent[x]);
      return parent[x];
  }  
    
    
};