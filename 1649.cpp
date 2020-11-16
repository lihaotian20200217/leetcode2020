/*
	LeetCode 1649
	给你一个整数数组instructions,你需要根据instructions中的元素创建一个
	有序数组。一开始你有一个空的数组nums，你需要从左到右遍历instructions
	中的元素，将它们依次插入nums数组中。每一次插入操作的代价是以下两者的
	较小值：
		nums中严格小于instructions[i]的数字数目。
		nums中严格大于instructions[i]的数字数目。
	比方说，如果要将 3 插入到 nums = [1,2,3,5] ，那么插入操作的 代价 为 min(2, 1) (元素 1 和  2 小于 3 ，元素 5 大于 3 ），插入后 nums 变成 [1,2,3,3,5] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-sorted-array-through-instructions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处		
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		int mod = 1e9+7;
		int n = 20;
		vector<int> bit;
		int lowbit(int x)
		{
			return x & (-x);
		}
		void add(int x)
		{
			while (x <= n)
			{
				bit[x] += 1;
				x += lowbit(x);
			}
		}
		int getSum(int x)
		{
			int ans = 0;
			while (x > 0)
			{
				ans += bit[x];
				x -= lowbit(x);
			}
			return ans;
		}
		int createSortedArray(vector<int>& instructions)
		{
			int res = 0;
			bit = vector<int>(n+1,0);
			for (int i = 0; i < instructions.size(); i++)
			{
				add(instructions[i]);
				int sum1 = getSum(instructions[i]-1);
				int sum2 = getSum(n);
				int sum3 = getSum(instructions[i]);
				res = (res + min(sum1,sum2-sum3)%mod) % mod;
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<int> arr = {1,3,3,3,2,4,2,1,2};
	cout << A.createSortedArray(arr) << endl;
	return 0;
}
