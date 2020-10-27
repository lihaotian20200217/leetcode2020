/*
	LeetCode 1626
	你想组合一支总体得分最高的球队。球队的得分是球队中所有球员的分数 总和 。

然而，球队中的矛盾会限制球员的发挥，所以必须选出一支 没有矛盾 的球队。如果一名年龄较小球员的分数 严格大于 一名年龄较大的球员，则存在矛盾。同龄球员之间不会发生矛盾。

*/

#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>& p1, vector<int>& p2)
{
	if (p1[0] < p2[0]) return true;
	else if (p1[0] == p2[0]) return p1[1] <= p2[1];
	return false;
}

int main()
{
	int n, x;
	cin >> n;
	vector<int> scores(n,0);
	vector<int> ages(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> scores[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ages[i];
	}
	vector<vector<int>> arr(ages.size(),vector<int>(2,0));
	for (int i = 0; i < ages.size(); i++)
	{
		arr[i][0] = ages[i];
		arr[i][1] = scores[i];
	}
	sort(arr.begin(),arr.end(),cmp);
	vector<int> dp(arr.size(),0);
	for (int i = 0; i < arr.size(); i++)
	{
		dp[i] = arr[i][1];
		for (int j = 0; j < i; j++)
		{
			if (arr[i][1] >= arr[j][1])
			{
				dp[i] = max(dp[i],dp[j]+arr[i][1]);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < dp.size(); i++)
	{
		res = max(res,dp[i]);
	}
	cout << res << endl;
	return 0;
}
