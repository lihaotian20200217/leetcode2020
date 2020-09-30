/*
    LeetCode-1035
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int col = A.size(), row = B.size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        unordered_map<int,int> a;
        unordered_map<int,int> b;
        for (int i = 1; i <= row; i++)
        {
            /*
            b[B[i-1]]++;
            for (int j = 1; j <= col; j++)
            {
                a[A[j-1]]++;
                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                if (A[j-1] == B[i-1])
                {
                    if (a[A[j-1]] == b[B[i-1]])
                    {
                        dp[i][j]++;
                    }
                }
            }
            a.clear();
            */
            for (int j = 1; j <= col; j++)
            {
                if (A[j-1] == B[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[row][col];
    }
};

int main()
{
    // 测试用例
    vector<int> A = {1,3,7,1,7,5};
    vector<int> B = {1,9,2,5,1};
    Solution Q;
    cout << Q.maxUncrossedLines(A,B) << endl;
    return 0;
}