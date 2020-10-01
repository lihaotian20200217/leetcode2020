/*
    LeetCode 797
*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> res;
        void dfs(unordered_map<int,vector<int>>& m, int id, vector<int>& arr, int end)
        {
            if (id == end)
            {
                arr.push_back(end);
                res.push_back(arr);
            }
            else
            {
                arr.push_back(id);
                for (int k = 0; k < m[id].size(); k++)
                {
                    dfs(m,m[id][k],arr,end);
                    arr.pop_back();
                }
                // arr.pop_back();
            }
            
        }
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            unordered_map<int,vector<int>> m;
            for (int i = 0; i < graph.size(); i++)
            {
                for (int j = 0; j < graph[i].size(); j++)
                {
                    m[i].push_back(graph[i][j]);
                }
            }
            vector<int> arr;
            dfs(m,0,arr,graph.size()-1);
            return res;
        }
};

int main()
{
    // 测试用例
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    Solution A;
    graph = A.allPathsSourceTarget(graph);
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
