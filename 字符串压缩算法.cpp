/*
	输入一串字符，请编写一个字符串压缩程序，将字符串中连续出现的重复字母进行压缩，并输出压缩后的字符串。
例如：
aac 压缩为 1ac
xxxxyyyyyyzbbb 压缩为 3x5yz2b
	输入描述：任意长度字符串
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	getline(cin,str); // 之所以这样写，是因为普通cin>>str遇到空格就自动结束了，这样才可以实现任意字符串的输入！
	str += "#";
	int id = 0, num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[id] != str[i])
		{
			int num = i - id - 1;
			string s = "";
			if (num) s += to_string(num);
			s += str[id];
			str.replace(id, i-id, s);
			i -= (i - id - s.size());
			id = i;
		}
	}
	cout << str.substr(0,str.size()-1) << endl;
	return 0;
}
