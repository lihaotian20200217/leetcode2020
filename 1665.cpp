/*
	LeetCode 1665 完成所有任务的最少初始能量！
	给你一个任务数组 tasks ，其中 tasks[i] = [actuali, minimumi] ：

actuali 是完成第 i 个任务 需要耗费 的实际能量。
minimumi 是开始第 i 个任务前需要达到的最低能量。
比方说，如果任务为 [10, 12] 且你当前的能量为 11 ，那么你不能开始这个任务。如果你当前的能量为 13 ，你可以完成这个任务，且完成它后剩余能量为 3 。

你可以按照 任意顺序 完成任务。

请你返回完成所有任务的 最少 初始能量。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
输入：tasks = [[1,2],[2,4],[4,8]]
输出：8
解释：
一开始有 8 能量，我们按照如下顺序完成任务：
    - 完成第 3 个任务，剩余能量为 8 - 4 = 4 。
    - 完成第 2 个任务，剩余能量为 4 - 2 = 2 。
    - 完成第 1 个任务，剩余能量为 2 - 1 = 1 。
注意到尽管我们有能量剩余，但是如果一开始只有 7 能量是不能完成所有任务的，因为我们无法开始第 3 个任务。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
	根据数据的规律发现actual与minimum差值越大的越要排到前面先算，若
	差值一样minimum越大的越要排在前面！
*/

class Solution {
	public:
		static bool cmp(vector<int>& p1, vector<int>& p2)
		{
			if (p1[1]-p1[0] != p2[1]-p2[0]) return (p1[1]-p1[0]) > (p2[1]-p2[0]);
			return p1[1] > p2[1];
		}
		int minimumEffort(vector<vector<int>>& tasks) {
			int res = 0, num = 0;
			sort(tasks.begin(),tasks.end(),cmp);
			for (int i = 0; i < tasks.size(); i++)
			{
				int count = max(tasks[i][0],tasks[i][1]);
				if (num >= count) num -= tasks[i][0];
				else
				{
					res += (count - num);
					num = count - tasks[i][0];
				}
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
	cout << A.minimumEffort(tasks) << endl;
	return 0;
}

























