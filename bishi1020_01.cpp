/*
	由于业绩优秀，公司给小Q放了n天的假，身为工作狂的小Q打算在假期中工作，锻炼或者休息。他有个奇怪的习惯，不会连续两天工作或锻炼。只有当公司营业时，小Q才能去工作，只有当健身房营业时，小Q才能去健身，小Q一天只能干一件事。给出假期中公司，健身房的营业情况，求小Q最少需要休息几天？
	1 代表营业 0 不营业
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	vector<int> arr(n,0);
	vector<int> brr(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[i] = x;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		brr[i] = x;
	}
	vector<vector<int>> dp(n+1,vector<int>(3,0));
	for (int i = 1; i <= n; i++)
	{
		if (arr[i-1] == 0 && brr[i-1] == 0)
		{
			dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
			dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
		}
		else if (arr[i-1] == 0 && brr[i-1] == 1)
		{
			dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
			dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1);
		}
		else if (arr[i-1] == 1 && brr[i-1] == 0)
		{
			dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1);
			dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
		}
		else
		{
			dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
			dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1);
			dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1);
		}
	}
	cout << n - max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;
	return 0;
}
