/*
	LeetCode 1653 使字符串平衡的最少删除次数
	给你一个字符串s，它仅包含字符'a'和'b'。
	你可以删除s中任意数目的字符，使得s平衡。我们称s平衡的当不存在下标对
	(i,j)满足i < j且s[i] = 'b' 同时 s[j] = 'a'。
	请返回使s平衡的最少删除次数
*/

#include <bits/stdc++.h>
uisng namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int len = s.size();
		vector<int> arr(len,0);
		vector<int> brr(len,0);
		arr[0] = (s[0] == 'b');
		brr[len-1] = (s[len-1] == 'a');
		for (int i = 1; i < len; i++)
		{
			arr[i] = arr[i-1] + (s[i] == 'b');
		}
		for (int i = len-2; i >= 0; i--)
		{
			brr[i] = brr[i+1] + (s[i] == 'a');
		}
		int res = len;
		for (int i = 1; i < len; i++)
		{
			res = min(res,arr[i-1]+brr[i]);
		}
		res = min(res,brr[0]);
		res = min(res,arr[len-1]);
		return res;
	}
	return 0;
}
