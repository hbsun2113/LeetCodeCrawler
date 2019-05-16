class Solution {
public:
    // 注意审题，不是求最大，而是求和 
    
    // 单调栈升级版，好写，还是基于一刷的思路，但是结构上更简单了
    int trap(vector<int>& height) {
        stack<int> s; // 单调递减栈
        int area=0;
        for(int i=0;i<height.size();i++){
            while(!s.empty() && height[s.top()]<=height[i]){
                int base=s.top();
                s.pop();
                if(s.empty()) break;
                int part=(i-s.top()-1)*(min(height[s.top()],height[i])-height[base]); 
                area+=part;
            }
            s.emplace(i);
        }
        return area;
    }
    
    // https://www.acwing.com/solution/LeetCode/content/121/
    // 这个解法主要是观察能力，便于记忆，实现简单，面试中建议这种写法。
    // 属于竖着计算面积(宽都是1)。对于每个位置来说，它能存储水的面积，在于它左右最高边界的高度。
    int trap2(vector<int>& height) {
        if(height.size()==0) return 0;
        vector<int> l(height.size()),r(height.size());
        l[0]=height[0];
        int tmp=height[0];
        for(int i=1;i<height.size();i++){
            tmp=max(tmp,height[i]);
            l[i]=tmp;
        }
        
        r[height.size()-1]=height[height.size()-1];
        tmp=height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            tmp=max(tmp,height[i]);
            r[i]=tmp;
        }
        
        int res=0;
        for(int i=0;i<height.size();i++)
            res+=min(l[i],r[i])-height[i];
        return res;
    }
    
    
    
    // 太难了！ 不容易记忆，不容易编码，但是利用了单调栈。所以也写一下，便于学习单调栈。
    // 以U型为单位处理计算面积，当前栈顶作为bottom，可以理解为横着算面积(宽)。每个U型是由左面“第一个”大于自己的、右面“第一个”大于自己的边界组成。
    // 单调栈的作用是保存左面第一个大于自己的元素。
    // 或者理解为以当前height为右边界向左搜索U型，计算其面积。
    int trap1(vector<int>& height) {
        if(height.size()==0) return 0;
        stack<int> s;
        int res=0;
        for(int i=0;i<height.size();i++){
            if(s.empty() || height[i]<height[s.top()]){
                s.push(i);
                continue;
            }
            else{
                while(!s.empty() && height[i]>=height[s.top()]){
                    if(height[i]==height[s.top()]){ //如果相等，说明同为一个bottom，还没有遇到右边界，暂时不处理。其实这个if去掉也不影响结果。
                        s.pop();
                        break;
                    }
                    int bottom=height[s.top()];
                    s.pop();
                    if(s.empty()) continue; //如果栈空了，说明没有左边界了，无法构成U型，自然不能储水。
                    int area=(i-s.top()-1)*(min(height[s.top()],height[i])-bottom);
                    cout<<i<<" "<<s.top()<<" "<<area<<endl;
                    res+=area;
                }
                s.push(i);
            }
        }
        return res;
    }
};