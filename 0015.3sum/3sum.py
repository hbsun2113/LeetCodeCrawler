class Solution(object):
    def threeSum1(self, nums):#改解法超时！！太暴力了
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result=[]
        dict={}
        for index in nums:
            dict.update({index:[]})
        for indexa in range(len(nums)):
            a=nums[indexa]
            for indexb in range(indexa+1,len(nums)):
                b=nums[indexb]
                if b in dict[a]:#剪枝
                    continue
                for indexc in range(indexb+1,len(nums)):
                    c=nums[indexc]
                    if c in dict[a] or c in dict[b]:
                        continue
                    if a+b+c==0 and (b not in dict[a] and c not in dict[a]) and (a not in dict[b] and c not in dict[b]) and (a not in dict[c] and b not in dict[a]):
                        dict[a].extend([b,c])
                        dict[b].extend([a,c])
                        dict[c].extend([b,a])
                        result.append([a,b,c])
        print (dict)
        return result
      
    #参考了Discuss
    #一点心得：还是双指针好使啊
    def threeSum(self, nums):
        nums.sort()
        result=[]
        for indexa in range(len(nums)):
            if indexa>0 and nums[indexa]==nums[indexa-1]:
                continue
            a=nums[indexa]
            indexb=min(indexa+1,len(nums)-1)
            indexc=len(nums)-1
            while indexb<indexc:
                if a+nums[indexb]+nums[indexc]<0:
                    indexb+=1
                elif a+nums[indexb]+nums[indexc]>0:
                    indexc-=1
                else :
                    result.append([a,nums[indexb],nums[indexc]])
                    while indexb<indexc and nums[indexb]==nums[indexb+1] :
                        indexb+=1
                    while indexb<indexc and nums[indexc]==nums[indexc-1] :
                        indexc-=1
                    indexb+=1
                    indexc-=1
        print (dict)
        return result
        
        
        
        
        
        
        
        
        
    
    