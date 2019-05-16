class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0) return 0;
        int area=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int h=min(height[i],height[j]);
            area=max(area,h*(j-i));
            while(i<j && height[i]<=h) i++;
            while(i<j && height[j]<=h) j--;
        }
        return area;
    }
};