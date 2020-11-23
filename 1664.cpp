/*
	LeetCode 1664 生成平衡数组的方案数
	给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。

比方说，如果 nums = [6,1,7,4,1] ，那么：

选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。

请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-make-a-fair-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入：nums = [2,1,6,4]
输出：1
解释：
删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
只有一种让剩余数组成为平衡数组的方案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-make-a-fair-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int waysToMakeFair(vector<int>& nums) {
			int res = 0, ji = 0, ou = 0;
			int len = nums.size();
			vector<int> even(len,0);
			vector<int> odd(len,0);
			for (int i = 0; i < len; i++)
			{
				if (i % 2 == 0)
				{
					ou += nums[i];
					even[i] = ou;
					if (i+1 < len) even[i+1] = ou;
				}
				else
				{
					ji += nums[i];
					odd[i] = ji;
					if (i+1 < len) odd[i+1] = ji;
				}
			}
			for (int i = 0; i < len; i++)
			{
				ji = 0, ou = 0;
				id (i % 2 == 0)
				{
					ou = even[i] + odd.back() - odd[i] - nums[i];
					ji = odd[i] + even.back() - even[i];
					if (ou == ji) res++;
				}
				else
				{
					ou = even[i] + odd.back() - odd[i];
					ji = odd[i] + even.back() - even[i] - nums[i];
					if (ou == ji) res++;
				}
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<int> arr = {1,1,1,1,1,1};
	cout << A.waysToMakeFair(arr) << endl;
	return 0;
}















