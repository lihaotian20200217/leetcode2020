/*
    LeetCode 1604
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string,queue<string>> m;
        set<string> Set;
        vector<string> res;
        //string pre0, pre1, aft0, aft1;
        for (int i = 0; i < keyName.size(); i++)
        {
            if (m.find(keyName[i]) != m.end() && m[keyName[i]].size() == 2)
            {
                string ss = m[keyName[i]].front();
                //cout << ss[0] << " " << ss[1] << endl;
                //pre0 = "", pre1 = "", aft0 = "", aft1 = "";
                //pre0 += ss[0] + ss[1];
                //aft0 += keyTime[i][0] + keyTime[i][1];
                //string pre1 = "" + m[keyName[i]].front()[3] + m[keyName[i]].front()[4];
                //pre1 += ss[3] + ss[4];
                //aft1 += keyName[i][3] + keyName[i][4];
                //int a = atoi(pre0.c_str()), b = atoi(aft0.c_str());
                //int c = atoi(pre1.c_str()), d = atoi(aft1.c_str());
                int a = (int)(ss[0] - '0') * 10 + (int)(ss[1] - '0');
                int b = (int)(keyTime[i][0] - '0') * 10 + (int)(keyTime[i][1] - '0');
                int c = (int)(ss[3] - '0') * 10 + (int)(ss[4] - '0');
                int d = (int)(keyTime[i][3] - '0') * 10 + (int)(keyTime[i][4] - '0');
                if (b >= a)
                {
                    if (!(b-a > 1 || (b-a == 1 && d > c))) Set.insert(keyName[i]);
                }
                
                m[keyName[i]].pop();
            }
            m[keyName[i]].push(keyTime[i]);
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