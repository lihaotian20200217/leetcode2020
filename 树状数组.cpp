#include <bits/stdc++.h>
using namespace std;

class BIT
{
	public:
		vector<int> arr;

		int getSum(int index)
		{
			int sum = 0;
			index = index + 1;
			while (index > 0)
			{
				sum += arr[index];
				index -= index & (-index);
			}
			return sum;
		}

		void updateBIT(int n, int index, int val)
		{
			index = index + 1;
			while (index <= n)
			{
				arr[index] += val;
				index += index & (-index);
			}
		}

		void constructBITree(vectot<int>& brr, int n)
		{
			arr = vector<int>(n+1,0);
			for (int i = 0; i < n; i++) updateBIT(n,i,brr[i]);
		}
};
