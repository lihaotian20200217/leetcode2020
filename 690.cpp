/*
    LeetCode 690
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(unordered_map<int,Employee*>& m, int id)
    {
        if (m[id]->subordinates.size() == 0) return m[id]->importance;
        else
        {
            for (auto ele : m[id]->subordinates)
            {
                m[id]->importance += solve(m,ele);
            }
            return m[id]->importance;
        }
    }
    int getImportance(vector<Employee*> employees, int id)
    {
        unordered_map<int,Employee*> m;
        for (int i = 0; i < employees.size(); i++)
        {
            m[employees[i]->id] = employees[i];
        }
        return solve(m,id);
    }
};
