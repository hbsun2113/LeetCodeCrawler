#不算水题，注意contain是矩形的，不是梯形
#http://www.jianshu.com/p/23e8e3e53abf
#http://blog.csdn.net/ljiabin/article/details/41673753
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i=0
        j=len(height)-1
        area=0
        while i!=j :
            area=max(area,min(height[i],height[j])*(j-i))
            if height[i]<height[j]:
                i+=1
            else :
                j-=1
        return area