class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = cmp(x, 0)
        r = int(`s*x`[::-1])
        return s*r * (r < 2**31)