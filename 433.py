'''
    LeetCode 433
'''

class Solution:
    res = 10
    def isright(self, cur: str, s: str) -> bool:
        c = 0
        for i in range(8):
            if cur[i] != s[i]:
                c += 1
            if c > 1:
                return False
        return c == 1
    def dfs(self, cur: str, end: str, bank: List[str], count: int, visit: List[bool]):
        if cur == end:
            self.res = min(self.res,count)
            return
        else:
            for i in range(len(bank)):
                if visit[i] and self.isright(cur,bank[i]):
                    visit[i] = False
                    self.dfs(bank[i],end,bank,count+1,visit)
                    visit[i] = True
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        visit = [True for i in range(len(bank))]
        self.dfs(start,end,bank,0,visit)
        if self.res == 10:
            return -1
        return self.res

if __name__ == '__main__':
    A = Solution()
    start = "AACCGGTT"
    end = "AAACGGTA"
    bank = ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
    print(A.minMutation(start,end,bank))