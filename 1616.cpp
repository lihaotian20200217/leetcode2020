/*
    LeetCode 1616
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(string& str1, string& str2, int left)
    {
        int right = str1.size() - 1 - left;
        while (left >= 0 && right < str1.size() && str1[left] == str2[right])
        {
            left--, right++;
        }
        return left;
    }
    bool checkPalindromeFormation(string a, string b) {
        int left = a.size() / 2 - 1;
        left = min(find(a,a,left),find(b,b,left));
        left = min(find(a,b,left),find(b,a,left));
        return left == -1;
    }
};

int main()
{
    // 测试用例
    Solution A;
    string str1 = "ulacfd";
    string str2 = "jizalu";
    cout << A.checkPalindromeFormation(str1,str2) << endl;
    return 0;
}