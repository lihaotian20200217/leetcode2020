/*
	明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。
	输入描述：注意：输入可能有多组数据。每组数据都包括多行，第一行先输入随机整数的个数N，接下来的N行再输入相应个数的整数。具体格式请看下面的"示例"。
	输出描述：返回多行，处理后的结果
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n,0);
		set<int> SET;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			SET.insert(arr[i]);
		}
		for (auto it : SET)
		{
			cout << it << endl;
		}
	}
	return 0;
}
