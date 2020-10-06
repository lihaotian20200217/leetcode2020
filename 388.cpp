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
        stack<vector<int>> stk;
        int cur = 0, i = 0, count = 0;
        while (i < input.size())
        {
            int end = input.find('\n',i);
            string str = input.substr(i,end - i);
            i = end + 1;
            vector<int> arr = {(int)str.size(),count};
            count = 0;
            while (i < input.size() && input[i] == '\t') i++, count++;
            while (stk.size() && stk.top()[1] >= arr[1]) cur -= stk.top()[0], stk.pop();
            if (stk.empty() || stk.top()[1] < arr[1]) cur += arr[0], stk.push(arr);
            if (str.find('.') != -1) res = max(res,cur+(int)stk.size()-1);
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