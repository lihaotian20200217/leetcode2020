/*
	给你一个整数数组 nums 和一个整数 k ，请你返回 非空 子序列元素和的最大值，子序列需要满足：子序列中每两个 相邻 的整数 nums[i] 和 nums[j] ，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。

数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/constrained-subsequence-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入：nums = [10,2,-10,5,20], k = 2
输出：37
解释：子序列为 [10, 2, 5, 20] 。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		/*
			dp[i]表示截止到i子序列的最大和
			dp[i] = max(dp[i-j],nums[i]); j = 1,2...k
			直接遍历浪费时间所以用单调队列维护最大值的索引
		*/
		int constrainedSubsetSum(vector<int>& nums, int k)
		{
			int len = nums.size();
			vector<int> dp(len,0);
			dp[0] = nums[0];
			deque<int> que;
			que.push_back(0);
			for (int i = 1; i < len; i++)
			{
				dp[i] = max(nums[i],dp[que.front()]+nums[i]);
				if (i-que.front() == k) que.pop_front();
				while (!que.empty() && dp[que.back()] < dp[i]) que.pop_back();
				que.push_back(i);
			}
			sort(dp.begin(),dp.end());
			return dp[len-1];
		}
};

int main()
{
	Solution A;
	vector<int> arr = {10,2,-10,5,20};
	cout << A.constrainedSubsetSum(arr,2) << endl;
	return 0;
}
