/*
	LeetCode 1647
	如果字符串s中不存在两个不同字符频次相同的情况，就称s是优质字符串。
	给你一个字符串s，返回使s成为优质字符串需要删除的最小字符数。
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		vector<int> arr(26,0);
		for (int i = 0; i < s.size(); i++)
		{
			arr[(int)(s[i]-'a')]++;
		}
		vector<int> brr;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i]) brr.push_back(arr[i]);
		}
		sort(brr.begin(),brr.end());
		int res = 0;
		for (int i = brr.size()-1; i >= 0; i--)
		{
			for (int j = brr.size()-1; j >= 0 && i != j; j--)
			{
				if (brr[i] == 0) break;
				if (brr[i] == brr[j])
				{
					brr[i]--;
					res++;
				}
			}
		}
		cout << res << endl;
	}	
	return 0;
}
