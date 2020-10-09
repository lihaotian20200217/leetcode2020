/*
    LeetCode 1604
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2)
    {
        if (p1[0] < p2[0]) return true;
        else if (p1[0] == p2[0]) return p1[1] <= p2[1];
        return false;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string,vector<vector<int>>> m;
        set<string> Set;
        vector<string> res;
        for (int i = 0; i < keyName.size(); i++)
        {
            int a = (int)(keyTime[i][0] - '0') * 10 + (int)(keyTime[i][1] - '0');
            int b = (int)(keyTime[i][3] - '0') * 10 + (int)(keyTime[i][4] - '0');
            m[keyName[i]].push_back({a,b});
        }
        for (auto item : m)
        {
            sort(item.second.begin(),item.second.end(),cmp);
            for (int i = 2; i < item.second.size(); i++)
            {
                if (item.second[i][0] >= item.second[i-2][0])
                {
                    if (!(item.second[i][0]-item.second[i-2][0] > 1 || (item.second[i][0]-item.second[i-2][0] == 1 && item.second[i][1] > item.second[i-2][1]))) Set.insert(item.first);
                }
            }
        }
        for (auto item : Set) res.push_back(item);
        return res;
    }
};
int main()
{
    vector<string> keyName = {"daniel","daniel","daniel","luis","luis","luis","luis"};
    vector<string> keyTime = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};
    Solution A;
    keyName = A.alertNames(keyName,keyTime);
    return 0;
}