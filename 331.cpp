/*
    LeetCode 331
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 0, sum = 0;
        //stack<char> stk;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (sum == 0)//if (stk.empty())
            {
                if (preorder[i] == ',') continue;
                else if (preorder[i] == '#')
                {
                    count--;
                    if (i != preorder.size()-1 && count < 0) return false;
                }
                else sum++;//else stk.push(preorder[i]);
            }
            else
            {
                if (preorder[i] == ',')
                {
                    count++;
                    sum = -1;// 因为底下还有个sum++;//while (stk.size()) stk.pop();
                }
                else if (preorder[i] == '#')
                {
                    count--;
                    if (i != preorder.size()-1 && count < 0) return false;
                }
                sum++;//else stk.push(preorder[i]);
            }
            /*if (preorder[i] == '#')
            {
                count--;
                if (i != preorder.size()-1 && count < 0) return false;
            }*/
        }
        if (sum) count++;//if (stk.size()) count++;
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