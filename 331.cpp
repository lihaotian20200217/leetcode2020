/*
    LeetCode 331
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 0;
        stack<char> stk;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (stk.empty())
            {
                if (preorder[i] == ',') continue;
                else if (preorder[i] == '#')
                {
                    count--;
                    if (i != preorder.size()-1 && count < 0) return false;
                }
                else stk.push(preorder[i]);
            }
            else 
            {
                if (preorder[i] == ',')
                {
                    count++;
                    while (stk.size()) stk.pop();
                }
                else if (preorder[i] == '#')
                {
                    count--;
                    if (i != preorder.size()-1 && count < 0) return false;
                }
                else stk.push(preorder[i]);
            }
        }
        if (stk.size()) count++;
        return count == -1;
    }
};

int main()
{
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution A;
    cout << A.isValidSerialization(preorder) << endl;
    return 0;
}