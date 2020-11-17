/*
	给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		bool isright(string s1, string s2)
		{// 比较是不是子串!
			int j = 0;
			for (int i = 0; i < s2.size(); i++)
			{
				if (s1[j] == s2[i]) j++;
			}
			return j == s1.size();
		}
		int findLUSlength(vector<string>& strs)
		{
			map<string,int> M;
			for (int i = 0; i < strs.size(); i++) M[strs[i]]++;
			int res = -1;
			for (auto it1 : M)
			{
				if (it1.second > 1) continue;
				int f = 0;
				for (auto it2 : M)
				{
					if (f > 1) break;
					if (isright(it1.first,it2.first)) f++;
				}
				if (f == 1)
				{
					if ((int)(it1.first.size()) > res) res = (int)(it1.first.size());
				}
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<string> strs = {"aba", "cdc", "eae"};
	cout << A.findLUSlength(strs) << endl;
	return 0;
}
