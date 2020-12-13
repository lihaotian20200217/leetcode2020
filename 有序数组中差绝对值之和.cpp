/*
	给你一个 非递减 有序整数数组 nums 。

请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i] 与数组中所有其他元素差的绝对值之和。

换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0 <= j < nums.length 且 j != i （下标从 0 开始）。

 

示例 1：

输入：nums = [2,3,5]
输出：[4,3,5]
解释：假设数组下标从 0 开始，那么
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
			vector<int> res(nums.size(),0);
			for (int i = 0; i < nums.size(); i++)
			{
				for (int j = 0; j < nums.size(); j++)
				{
					if (j != i)
					{
						res[i] += abs(nums[j] - nums[i]);
					}
				}
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<int> nums = {2,3,5};
	nums = A.getSumAbsoluteDifferences(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}















