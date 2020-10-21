/*
	LeetCode 1619
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		double trimMean(vector<int>& arr)
		{
			double res = 0.0;
			sort(arr.begin(),arr.end());
			int len = arr.size();
			int num = len / 20;
			for (int i = num; i < len - num; i++)
			{
				res += arr[i];
			}
			return res / (len - 2*num);
		}
};

int main()
{
	Solution A;
	int n, x;
	cin >> n;
	vector<int> arr(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << A.trimMean(arr) << endl;
	return 0;
}
