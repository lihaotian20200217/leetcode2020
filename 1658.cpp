/*
	LeetCode 1658.将x减到0的最小操作数
	给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	实例1：
	输入：nums = [1,1,4,2,3], x = 5
	输出：2
	解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minOperations(vector<int>& nums, int x) {
			int sum = 0, res = INT_MIN, len = nums.size();
			vector<int> arr(len+1,0);
			for (int i = 0; i < len; i++)
			{
				//arr.push_back(arr.back()+nums[i]);
				arr[i+1] = arr[i] + nums[i];
			}
			if (arr.back() < x) return -1;
			int id = 0;
			sum = arr.back() - x;
			for (int i = 1; i < len+1; i++)
			{		
				while (arr[i] - arr[id] >= sum)
				{
					if (arr[i] - arr[id] == sum)
					{
						res = max(res,i-id);
						id++;
						break;
					}
					id++;
				}	
			}
			if (res == INT_MIN) return -1;
			return len - res;
		}
};


int main()
{
	Solution A;
	vector<int> nums = {1,1,4,2,3};
	cout << A.minOperations(nums,5) << endl;
	return 0;
}













