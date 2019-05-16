class Solution(object):
    
    #解题思路有问题 麻烦而且不对
    def generateParenthesis1(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        n=2
        result={}
        if n==1:
            return '()'
        self.generatenext('()',n-1,result)
        return result.keys()
    
    def inner(self,str):
        return str[:1]+'()'+str[1:]
    def outer(self,str):
        return "("+str+')'
    def bl(self,str):
        return str+'()'
    
    def generatenext(self,str,other,result):
        if other==1:
            result.update({self.inner(str):''})
            result.update({self.outer(str):''})
            result.update({self.bl(str):''})
            return 
        self.generatenext(self.inner(str),other-1,result)
        self.generatenext(self.outer(str),other-1,result)
        self.generatenext(self.bl(str),other-1,result)
        
        
    def generateParenthesis(self,n,string='',myopen=0,myclose=0,result=[]):
        #print (result)
        if myopen==0 and myclose==0:
            result=[]
        if myopen<n:
            #print (myopen,n)
            self.generateParenthesis(n,string+'(',myopen+1,myclose,result)
        if myclose<myopen:
            print (myclose,myopen)
            self.generateParenthesis(n,string+')',myopen,myclose+1,result)
        if len(string)==2*n or (myopen==0 and myclose==0):
            #print (result)
            #print (string)
            if not(myopen==0 and myclose==0):
                result.append(string)
            #print (result,string)
            return result  
        
    
