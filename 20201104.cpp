/*
    给定一个数组序列，需要求选出一个区间，使得该区间是所有区间中经过如下计算
    的值的最大的一个：
    区间中的最小数*区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出
    具体的区间。区间内的所有数字都在【0,100】的范围内；
    输入描述：
    第一行输入数组序列长度n,第二行输入数组序列。
    对于50%的数据，1 <= n <= 10000;
    对于100%的数据，1 <= n <= 500000;
    输出描述：
    输出数组经过计算后的最大值。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int res = INT_MIN；
	for (int i = 0; i < n; i++)
	{
		int j = i;
		int k = i-1;
		int sum1 = 0;
		while (arr[i] <= arr[j] && j < n)
		{
			sum1 += arr[j];
			j++;
		}
		while (arr[k] >= arr[i] && k >= 0)
		{
			sum1 += arr[k];
			k--;
		}
		res = max(res,sum1*arr[i]);
	}
	cout << res << endl;
	return 0;
}
