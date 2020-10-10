/*
	LeetCode 1234
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // 'Q' 'w' 'E' 'R'
	int balancedString(string s) {
		int len = s.size();
		vector<vector<int>> arr(len+1,vector<int>(4,0));
		for (int i = 1; i <= len; i++)
		{
			if (s[i-1] == 'Q')
			{
				arr[i][0] = arr[i-1][0] + 1;
				arr[i][1] = arr[i-1][1];
				arr[i][2] = arr[i-1][2];
				arr[i][3] = arr[i-1][3];
			}
			else if (s[i-1] == 'W')
			{
				arr[i][0] = arr[i-1][0];
				arr[i][1] = arr[i-1][1] + 1;
				arr[i][2] = arr[i-1][2];
				arr[i][3] = arr[i-1][3];
			}
			else if (s[i-1] == 'E')
			{
				arr[i][0] = arr[i-1][0];
				arr[i][1] = arr[i-1][1];
				arr[i][2] = arr[i-1][2] + 1;
				arr[i][3] = arr[i-1][3];
			}
			else
			{
				arr[i][0] = arr[i-1][0];
				arr[i][1] = arr[i-1][1];
				arr[i][2] = arr[i-1][2];
				arr[i][3] = arr[i-1][3] + 1;
			}
		}
		int res = len, i = 0, j = 1, L = len/4;
		if (arr[len][0] == L && arr[len][1] == L && arr[len][2] == L) return 0;
		while (i < j)
		{
			int q = arr[j][0] - arr[i][0];
			int w = arr[j][1] - arr[i][1];
			int e = arr[j][2] - arr[i][2];
			int r = arr[j][3] - arr[i][3];
			int q2 = arr[len][0] - q;
			int w2 = arr[len][1] - w;
			int e2 = arr[len][2] - e;
			int r2 = arr[len][3] - r;
			if (q2>L || w2>L || e2>L || r2>L)
			{
				j++;
				if (j > len)
				{
					j = len;
					i++;
				}
			}
			else
			{
				res = min(res,j-i);
				i++;
			}
		}
		return res;
	}
};

int main()
{
	// 测试用例
	string s = "QWER";
	Solution A;
	cout << A.balancedString(s) << endl;
	return 0;
}
