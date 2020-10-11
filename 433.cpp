/*
    LeetCode 433
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res = 10;
    bool isright(string& cur, string& str)
    {
        int c = 0;
        for (int i = 0; i < 8; i++)
        {
            if (cur[i] != str[i]) c++;
            if (c > 1) return false;
        }
        return c == 1;
    }
    void dfs(string& cur, string& end, vector<string>& bank, int count,vector<bool>& visit)
    {
        if (cur == end)
        {
            res = min(res,count);
            return;
        }
        for (int i = 0; i < bank.size(); i++)
        {
            if (visit[i] && isright(cur,bank[i]))
            {
                visit[i] = false;
                dfs(bank[i],end,bank,count+1,visit);
                visit[i] = true;
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> visit(bank.size(),true);
        dfs(start,end,bank,0,visit);
        return res == 10 ? -1 : res;
    }
};

int main()
{
    // 测试用例
    Solution A;
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << A.minMutation(start,end,bank) << endl;
    return 0;
}