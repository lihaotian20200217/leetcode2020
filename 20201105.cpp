/*
	LeetCode 1049 最后一块石头的重量II
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lastStoneWeightII(vector<int>& stones)
		{
			int sum = 0, num = 0, res = 0;
			for (int i = 0; i < stones.size(); i++) sum += stones[i];
			vector<int> dp(sum/2+1,0);
			for (int i = 0; i < stones.size(); i++)
			{
				for (int j = sum/2; j >= 0 && j >= stones[i]; j--)
				{
					dp[j] = max(dp[j],dp[j-stones[i]]+stones[i]);
				}
			}
			return sum - 2 * dp[sum/2];
		}
};

int main()
{

	Solution A;
	vector<int> stones = {31,26,33,21,40};
	cout << A.lastStoneWeightII(stones) << endl;
	return 0;
}
