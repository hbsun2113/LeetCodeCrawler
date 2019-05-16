class Solution {
public:
    // 四刷，自己做出来了。
    
    // 这种题目秉持一个原则：每个位置只负责自己的高度。
    // 如何确定左右边界：左右两侧第一个比自己小的。（这里的第一个 指的 是最近的）
    // 问题转变为什么时候开始结算：当在后续中遇到比自己小的就要结算了。(因为不可以继续延伸了)。此时右边界就是i。
    // 其实此时就可以确定要使用的是 单调递增栈
    // 左边界也可以确定是 栈中的前继节点。
    
    // 一点小经验：先写出while循环，再确定是单调递增栈还是单调递减栈
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        heights.push_back(INT_MIN); // 为确保最后栈为空，最后压入一个最小的。
        stack<int> s; // 单调递增栈：遇到更大的压栈，遇到小的就不停地弹栈。
        int res=0;
        for(int i=0;i<heights.size();i++){
            res=max(res,heights[i]);
            while(!s.empty() && heights[i]<heights[s.top()]){
                int h=heights[s.top()];
                s.pop();
                int w=i; // 注意也有可能没有左边界。
                if(!s.empty()){
                    w=i-s.top()-1;
                }
                res=max(res,w*h);
                
            }
            s.push(i);
        }
        return res;
    }
    
    // 三刷，还是没有自己做出来，但是规范了代码结构
    int largestRectangleArea3(vector<int>& heights) {
        if(heights.size()==0) return 0;
        heights.push_back(INT_MIN);
        stack<int> s;
        int res=INT_MIN;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[i]<heights[s.top()]){
                int h=heights[s.top()];
                s.pop();
                int w;
                if(!s.empty())
                    w=i-s.top()-1;
                else 
                    w=i;    
                res=max(res,w*h);
            }
            s.push(i);
        }
        return res;
    }
    
    
    //做了好久 也没完全明白 最好每一步都自己推演一遍吧http://blog.csdn.net/kenden23/article/details/17487665
//https://siddontang.gitbooks.io/leetcode-solution/content/array/largest_rectangle_in_histogram.html


//二更，还是没有做出来，并且答案也是看了好久才想明白。还是看上面两个的博客。我觉得自己凭空写出这道题的可能性比较小，现在自然语言描述，用于记忆。
/*
1.每个方柱计算只需要计算以自己为高度的最大面积矩形就可以了（设该位置为bar），不需要考虑比自己低的方柱，因为比自己低的方柱是由比自己低的方柱负责的！因此我们说bar的矩形 就是 以bar的高度为高度的矩形。
2.问题的核心变为如何确定每个bar的矩形的左右边界。
3.设计一个栈，如果当前位置n的高度小于栈顶元素，就开始弹栈，并且以栈顶元素为bar计算它的直方图，首先当前元素的右边界肯定是n（因为该栈是递增栈）,左边界是当前栈顶的元素(也是因为该栈是递增栈)。
4.这样对于每个bar都可以计算它对应的矩形的面积了。注意一开始要压栈一个最小值，这样保证了每个bar都被计算过。*/
    int largestRectangleArea1(vector<int>& heights) {
        heights.push_back(-10);//最右面加上一个最小值，用来后续清空栈
        stack<int> s;
        int maxarea=0;
        for(int i=0;i<heights.size();){//注意只有压栈的时候才去增加i 要不然i一直作为左边界。
            if(s.empty() || heights[i]>heights[s.top()]){//注意没有等号 考虑这样的情况 2 1 5 6 5 2 3
                //cout<<i<<endl;
                s.push(i++);
            }
            else{
                int index=s.top();
                s.pop();
                int height=heights[index];//每次计算的是从栈弹出的索引对应的高度的矩形面积
                int width=s.empty()?i:i-s.top()-1;//这一步也比较讲究 由于i是右面第一个小于它的 所以要求宽度的话 只要用右边界减去左边界就可以
                //cout<<i<<" "<<height<<" "<<width<<endl;
                maxarea=max(maxarea,height*width);
            }
        }
        return maxarea;
        
    }
    
};