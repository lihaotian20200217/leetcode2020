class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        d = []
        f = []
        for i in range(len(nums)+1):
            d.append(0)
            f.append(0)
        for i in range(len(requests)):
            d[requests[i][0]] += 1
            d[requests[i][1]+1] -= 1
        for i in range(1,len(d),1):
            f[i] = f[i-1] + d[i-1]
        f[0] = -1
        nums.sort()
        f.sort()
        res = 0
        for i in range(len(nums)):
            res = (res + nums[i] * f[i+1]) % 1000000007
        return res

        
