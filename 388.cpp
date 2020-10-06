/*
    LeetCode 388
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res = 0;
    int lengthLongestPath(string input) {
        input += '\n';
        stack<pair<int,int>> sk;
        int i = 0, tab = 0, cur = 0;
        while (i < input.size())
        {
            int end = input.find('\n',i);
            string tmp = input.substr(i,end-i);
            i = end + 1;
            pair<int,int> eme = make_pair(tmp.size(),tab);
            tab = 0;
            while (i < input.size() && input[i] == '\t')
            {
                i++, tab++;
            }
            while (!sk.empty() && sk.top().second >= eme.second)
            {
                cur -= sk.top().first;
                sk.pop();
            }
            if (sk.empty() || sk.top().second < eme.second)
            {
                cur += tmp.size();
                sk.push(eme);
            }
            if (tmp.find('.') != -1) res = max(res,cur+(int)sk.size()-1);
        }
        return res;
    }
};

int main()
{
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    Solution A;
    cout << A.lengthLongestPath(input) << endl;
    return 0;
}