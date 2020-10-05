/*
    LeetCode 5518
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();
        vector<vector<int>> res(row,vector<int>(col,0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int num = min(rowSum[i],colSum[j]);
                res[i][j] = num;
                rowSum[i] -= num;
                colSum[j] -= num;
            }
        }
        return res;
    }
};

int main()
{
    // 测试用例
    vector<int> rowSum = {3,8};
    vector<int> colSum = {4,7};
    Solution A;
    vector<vector<int>> res;
    res = A.restoreMatrix(rowSum,colSum);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}