/*
	写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。
	输入描述：输入一个十六进制的数值字符串。注意：一个用例会同时有多组输入数据，请参考帖子https://www.nowcoder.com/discuss/276处理多组输入的问题。
	输出描述：输出该数值的十进制字符串。不同组的测试用例用\n隔开。
*/

#include <bits/stdc++.h>
uisng namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		vector<char> arr;
		for (int i = 2; i < str.size(); i++)
		{
			arr.push_back(str[i]);
		}
		int res = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == 'A')
			{
				res += 10 * pow(16,arr.size()-1-i);
			}
			else if (arr[i] == 'B')
			{
				res += 11 * pow(16,arr.size()-1-i);
			}
			else if (arr[i] == 'C')
			{
				res += 12 * pow(16,arr.size()-1-i);
			}
			else if (arr[i] == 'D')
			{
				res += 13 * pow(16,arr.size()-1-i);
			}
			else if (arr[i] == 'E')
			{
				res += 14 * pow(16,arr.size()-1-i);
			}
			else if (arr[i] == 'F')
			{
				res += 15 * pow(16,arr.size()-1-i);
			}
			else 
			{
				res += (int)(arr[i] - '0') * pow(16,arr.size()-1-i);
			}
		}
		cout << res << endl;
	}
	return 0;
}
