/*
	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

*/

#include <bits/stdc++.h>
using namespace std;
bool function()
{
	int x;
	char c;
	vector<int> arr;
	while ((cin >> x).get(c))
	{
		arr.push_back(x);
		if (c == '\n') break;
	}
	if (arr.size() == 0) return true;
	// 我们认为最开始的树只有左子树！
	int r = INT_MAX;
	stack<int> stk;
	for (int i = arr.size()-1; i >= 0; i--)
	{
		if (arr[i] > r) return false;
		/*
		如果是右子树的话我们一直更新根节点！
		*/
		while (!stk.empty() && arr[i] < stk.top())
		{
			r = stk.top();
			stk.pop();
		}
		stk.push(arr[i]);// 每一次压入当前位置下的根节点对应的右结点!
	}
	return true;
}
int main()
{
	cout << function() << endl;
	return 0;
}
