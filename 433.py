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


'''
__name__是python的一个内置类属性，它天生就存在于一个 python 程序中，代表对应程序名称
直接运行433.py 时：__name__="__main__"
在其它程序中导入433.py，则：__name__="433.py"
从例子中的输出内容可以看出，直接运行py文件和导入py文件输出的__name__值不同，因此通过判断__name__的值，
就可以区分py文件是直接被运行，还是被引入到其他程序中。

具体情境：
1、项目领导给你安排一个任务，写一个模块。
2、通常编写完成程序代码，会在结尾写上一些测试信息，来验证程序是否正确。
3、这样就产生了一个问题，领导引用你的模块，也会运行这个测试内容。
4、这时只要在测试内容前面加上：if __name__ == '__main__':
那么，编写调试过程直接运行该模块时__name__ = "__main__",测试内容被执行。
而领导调用它，__name__ != "__main__"，测试内容则不会被执行，完美的解决了这个问题。
'''