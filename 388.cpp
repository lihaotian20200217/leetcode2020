/*
    LeetCode 388
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        // 用栈
        stack<char> stk;
        int res = -1, count = 0, f = 0, layer = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '.') f++;
            if (input[i] != '\n') stk.push(input[i]);
            else
            {
                if (input[i] == '.') f++;
                count = 0;
                // 计算是第几层 count 
                int j = i, sum = 0;
                while (j < input.size()-1)
                {
                    if (input[j] == '\n')
                    {
                        j++;
                    }
                    else if (input[j] == '\t')
                    {
                        j++;
                        count++;
                        //if (count == layer+1) break;
                    }
                    else if (input[j] == ' ')
                    {
                        sum++;
                        j++;
                        if (sum == 4)
                        {
                            sum = 0;
                            count++;
                            if (count == layer+1) break;
                        }
                    }
                    else break;
                }
                i = j - 1;

                // 如果 count > layer, 更新layer push('\\'),继续
                if (count > layer)
                {
                    layer = count;
                    stk.push('\\');
                }
                else
                {
                    // 反之，出栈直到 count = layer-1
                    res = max(res,(int)stk.size());
                    //cout << res << endl;
                    while (layer >= count)
                    {
                        layer--;
                        while (stk.top() != '\\') stk.pop();
                        stk.pop(); 
                    } //cout << stk.top() << endl;
                    stk.push('\\'); // 最后一次的不能弹出
                    layer = count; // 恢复到count层
                }
            }
        } //cout << input.size();
        res = max(res,(int)stk.size());
        if (!f) return 0;
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