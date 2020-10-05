'''
    LeetCode 5518
'''

class Solution:
    #def __init__(self):
        #pass
    def restoreMatrix(self,rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        row, col = len(rowSum), len(colSum)
        res = [[0 for i in range(col)] for j in range(row)]
        for i in range(row):
            for j in range(col):
                num = min(rowSum[i],colSum[j])
                res[i][j] = num
                rowSum[i] = rowSum[i] - num
                colSum[j] = colSum[j] - num
        return res

rowSum, colSum = [3,8], [4,7]
A = Solution()
arr = A.restoreMatrix(rowSum,colSum)
print(arr)