/*
    1599. 经营摩天轮的最大利润
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int res = 0, id = 0, f = 0, profit = 0, num = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            num += customers[i];
            if (num <= 4)
            {
                profit += (num * boardingCost - runningCost);
                num = 0;
            }
            else 
            {
                profit += (4 * boardingCost - runningCost);
                num -= 4;
            }
            f++;
            if (profit > res)
            {
                res = profit;
                id = f;
            }
        }
        while (num)
        {
            f++;
            if (num <= 4)
            {
                profit += (num * boardingCost - runningCost);
                if (profit > res) id = f;
                break;
            }
            else 
            {
                profit += (4 * boardingCost - runningCost);
                num -= 4;
            }
            if (profit > res)
            {
                res = profit;
                id = f;
            }
        }
        return res == 0 ? -1 : id;
    }
};

int main()
{
    // 测试用例
    vector<int> customers = {10,9,6};
    int boardingCost = 6, runningCost = 4;
    Solution A;
    cout << A.minOperationsMaxProfit(customers,boardingCost,runningCost) << endl;
    return 0;
}