/*
	LeetCode 拆炸弹
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> decrypt(vector<int>& code, int k)
		{
			if (k == 0) return vector(code.size(),0);
			vector<int> arr;
			for (int i = 0; i < code.size(); i++)
			{
				arr.push_back(code[i]);
			}
			for (int i = 0; i < code.size(); i++)
			{
				arr.push_back(code[i]);
			}
			if (k > 0)
			{
				for (int i = 0; i < code.size(); i++)
				{
					code[i] = 0;
					for (int j = i+1; j <= i+k; j++)
					{
						code[i] += arr[j];
					}
				}
			}
			else
			{
				k = -k;
				for (int i = code.size()-1, p = 0; i >= 0; i--,p++)
				{
					code[i] = 0;
					for (int j = arr.size()-2-p; j >= arr.size()-1-p-k; j--)
					{
						code[i] += arr[j];
					}
				}
			}
			return code;
		}
};

int main()
{
	Solution A;
	vector<int> code = {5,7,1,4};
	code = A.decrypt(code,3);
	for (int i = 0; i < code.size(); i++) cout << code[i] << " ";
	return 0;
}
