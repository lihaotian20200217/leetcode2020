/*
    1598.文件夹操作日志搜集器
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<bool> stk;
        for (int i = 0; i < logs.size(); i++)
        {
            if (logs[i] == "../")
            {
                if (stk.size() != 0) stk.pop();
            }
            else if (logs[i] != "./")
            {
                stk.push(true);
            }
        }
        return stk.size();
    }
};

int main()
{
    Solution A;
    // 测试用例
    vector<string> logs = {"d1/","d2/","./","d3/","../","d31/"};
    cout << A.minOperations(logs) << endl;
    return 0;
}