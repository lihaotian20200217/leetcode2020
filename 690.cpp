/*
    LeetCode 690
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto ele : employees)
        {
            if (ele->id == id)
            {
                if (ele->subordinates.size() == 0) return ele->importance;
                else
                {
                    for (auto ID : ele->subordinates)
                    {
                        ele->importance += getImportance(employees,ID);
                    }
                    return ele->importance;
                }
                
            }
        }
        return 0;
    }
};