/*
	LeetCode 853
	思路：我们将车的位置按照从大到小的顺序排序，并且计算每个位置用对应的速度到终点的时间如果相邻的位置较小的车用的时间比前面的车少，
	那么它们一定会形成一个车队，并且把该车到终点的时间改为它前面一辆车到终点的时间！
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	piublic:
		int carFleet(int target, vector<int>& position, vector<int>& speed)
		{
			int res = 1;
			vector<vector<double>> arr(position.size(),vector<double>(2,0));
			for (int i = 0; i < position.size(); i++)
			{
				arr[i][0] = position[i];
				arr[i][1] = (target - position[i]) / (double)speed[i];
			}
			sort(arr.rbegin(),arr.rend());
			if (arr.size() == 0) res--;
			for (int i = 1; i < arr.size(); i++)
			{
				if (arr[i][1] <= arr[i-1][1])
				{
					arr[i][1] = arr[i-1][1];
				}
				else res++;
			}
			return res;
		}
};

int main()
{
	Solution A;
	int target, m;
	cin >> target >> m;
	vector<int> position(m,0);
	vector<int> speed(m,0);
	for (int i = 0; i < m; i++)
	{
		cin >> position[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> speed[i];
	}
	cout << A.carFleet(target,position,speed) << endl;
	return 0;
}
