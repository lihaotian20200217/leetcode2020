/*
	如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：

操作 1：交换任意两个 现有 字符。
例如，abcde -> aecdb
操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
你可以根据需要对任意一个字符串多次使用这两种操作。

给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-if-two-strings-are-close
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

	示例1：
	输入：word1 = "abc", word2 = "bca"
	输入: true
	共两次操作：
	1. "abc" -> "acb"
	2. "acb" -> "bca"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		bool closeStrings(string word1, string word2) {
			if (word1.size() != word2.size()) return false;
			map<char,int> m1;
			map<char,int> m2;
			for (int i = 0; i < word1.size(); i++) m1[word1[i]]++;
			for (int i = 0; i < word2.size(); i++) m2[word2[i]]++;
			if (m1.size() != m2.size()) return false;
			for (auto it1 : m1)
			{
				if (m2.find(it1.first) == m2.end()) return false;
				if (m2[it1.first] == it1.second)
				{
					m1.erase(it1.first);
					m2.erase(it1.first);
				}
				else
				{
					for (auto ele : m2)
					{
						if (ele.second == it1.second)
						{
							m2[ele.first] = m2[it1.first];
							m1.erase(it1.first);
							m2.erase(it1.first);
							break;
						}
					}
				}
			}
			return m2.size() == 0;
		}
};

int main()
{
	Solution A;
	string word1 = "abc", word2 = "bca";
	cout << A.closeStrings(word1, word2) << endl;
	return 0;
}
