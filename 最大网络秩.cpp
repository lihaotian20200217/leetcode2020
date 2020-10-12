/*
    LeetCode 5536
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> M;
        map<vector<int>,int> Map;
        int res = 0, cur = 0;
        for (int i = 0; i < roads.size(); i++)
        {
            M[roads[i][0]].push_back(roads[i][1]);
            M[roads[i][1]].push_back(roads[i][0]);
            Map[roads[i]] = 1;
            Map[{roads[i][1],roads[i][0]}] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                cur = M[i].size() + M[j].size();
                if (Map[{i,j}] != 0 || Map[{j,i}] != 0) cur--;
                res = max(res,cur);
            }
        }
        return res;
    }
};

int main()
{
    // 测试用例
    Solution A;
    int n = 4;
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    cout << A.maximalNetworkRank(n,roads) << endl;
    return 0;
}