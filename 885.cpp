#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int len = R * C;
        vector<vector<int>> res(len,vector<int>(2,-1));
        int step = 2, i = r0, j = c0, idx = 0, id = 0;
        while (res[len-1][0] == -1)
        //while (res.size() < len)
        {
            while (idx < step)
            {
                if (i>=0&&i<R&&j>=0&&j<C)
                {
                    res[id][0] = i, res[id][1] = j, id++;//res.push_back({i,j});
                }
                idx++;
                j++;

            }
            idx = 1;i++;j--;
            while (idx < step)
            {
                if (i>=0&&i<R&&j>=0&&j<C)
                {
                    res[id][0] = i, res[id][1] = j, id++;//res.push_back({i,j});
                }
                idx++;
                i++;

            }
            step++;idx = 1;i--;j--;
            while (idx < step)
            {
                if (i>=0&&i<R&&j>=0&&j<C)
                {
                    res[id][0] = i, res[id][1] = j, id++;//res.push_back({i,j});
                }
                idx++;
                j--;

            }
            idx = 1;i--;j++;
            while (idx < step)
            {
                if (i>=0&&i<R&&j>=0&&j<C)
                {
                    res[id][0] = i, res[id][1] = j, id++;//res.push_back({i,j});
                }
                idx++;
                i--;

            }
            step++;idx = 1;i++;j++;
        }
        return res;
    }
};

int main()
{
    Solution A;
    vector<vector<int> > res;
    int R, C, r0, c0;
    cin >> R >> C >> r0 >> c0;
    res = A.spiralMatrixIII(R,C,r0,c0);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}