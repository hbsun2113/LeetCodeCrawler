#https://www.cnblogs.com/kepuCS/p/5271654.html
#这道题目不算水，我做了好久，一开始思路错了，要想到用回溯。
#http://lib.csdn.net/article/datastructure/16705迭代解法也很清晰。
class Solution(object):
    dic={u'2':['a','b','c'],u'3':['d','e','f'],u'4':['g','h','i'],u'5':['j','k','l'],u'6':['m','n','o'],u'7':['p','q','r','s'],u'8':['t','u','v'],u'9':['w','x','y','z']}
    def recuive_combine(self,index,cur,digits,result):
        if index==len(digits) and len(cur)!=0:
            result.append(cur)
            return
        v=self.dic[digits[index]]
        for vv in v:
            self.recuive_combine(index+1,cur+vv,digits,result)
            
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        #digits=u'23'
        if len(digits)==0:
            return []
        result=[]
        self.recuive_combine(0,'',digits,result)
        return result
                
    
        
        
        
        
        
        
        
        
        
        
        
        