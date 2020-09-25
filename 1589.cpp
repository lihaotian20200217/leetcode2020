/*
    LeetCode-1589
    利用贪心+差分数组求解
    差分数组
    差分数组就是数组存储某数组后一项与前一项的差：d[i] = nums[i] - nums[i-1];
    例如 nums = [1,2,3,4,5], 其差分数组为：d = [1,1,1,1,1]。然后差分数组在区间修改的运动中，例如让
    [1,3]区间各自加1，由于差分数组的性质，d数组只有d[1]和d[4]有所改变，即d[1]++,d[4]--。再通过差分数组
    求原数组，由于d[i] = nums[i] - nums[i-1]；即nums[i] = d[i] + nums[i-1]；通过这样求区间修改过后
    的数组时间复杂度能优化到O(n)。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int mod = 1000000007;
        // 构建差分数组
        vector<int> d(nums.size()+1,0);
        vector<int> f(nums.size()+1,0);
        for (int i = 0; i < requests.size(); i++)
        {
            d[requests[i][0]]++; // 区间内的首个位置差分值加一
            d[requests[i][1]+1]--; // 区间外的第一个位置差分值减一
            // 因为是通过递推完成给区间内每一个数计数，如果区间外的第一个位置
            // 不减一，那么会一直增加下去！
        }
        for (int i = 1; i < f.size(); i++)
        {   // d[i-1] 存放 f[i] 与 f[i-1] 的差值
            f[i] = f[i-1] + d[i-1];
        }
        f[0] = INT_MIN;// 下标为0没有实际用处，防止参与计算
        // 利用贪心的思想
        sort(nums.begin(),nums.end());
        sort(f.begin(),f.end());
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {   // 权重值是从下标为1开始计算的
            res = (res + f[i+1] * nums[i]) % mod;
        }
        return res;
    }
};

int main()
{
    // 测试样例
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> requests = {{1,3},{0,1}};
    Solution A;
    cout << A.maxSumRangeQuery(nums,requests) << endl;
    return 0;
}