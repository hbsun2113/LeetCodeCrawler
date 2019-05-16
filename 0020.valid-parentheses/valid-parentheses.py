#括号匹配 大水题
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        result=[]
        slength=len(s)
        for c in s :
            if c =='(' or c=='{' or c=='[':
                result.append(c)
            else :
                if len(result)==0:
                    return False
                tail=result.pop()
                print (tail)
                if c==')' and tail=='(' or c=='}' and tail=='{' or c==']' and tail=='[' :
                    continue
                else :
                    return False
        if len(result)==0:
            return True
        else :
            return False