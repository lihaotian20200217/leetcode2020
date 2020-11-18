/*
	LeetCode 1439 有序数组中的第k个最小数组和
	给你一个 m * n 的矩阵 mat，以及一个整数 k ，矩阵中的每一行都以非递减的顺序排列。

你可以从每一行中选出 1 个元素形成一个数组。返回所有可能数组中的第 k 个 最小 数组和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入：mat = [[1,3,11],[2,4,6]], k = 5
输出：7
解释：从每一行中选出一个元素，前 k 个和最小的数组分别是：
[1,2], [1,4], [3,2], [3,4], [1,6]。其中第 5 个的和是 7 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		int kthSmallest(vector<vector<int>>& mat, int k)
		{
			int m = mat.size(), n = mat[0].size();
			multiset<int> s(mat[0].begin(), mat[0].end());
			for (int i = 1; i < m; i++)
			{
				multiset<int> temp;
				for (int x1 : s)
				{
					for (int x2 : mat[i])
					{
						temp.insert(x1+x2);
					}
				}
				s.clear();
				auto it = temp.begin();
				for (int j = 0; j < min(k,(int)temp.size()); j++, it++)
				{
					s.insert(*it);
				}
			}
			return *s.rbegin();
		}
};

int main()
{
	Solution A;
	vector<vector<int>> mat = { {1,3,11}, {2,4,6} };
	cout << A.kthSmallest(mat,5) << endl;
	return 0;
}
