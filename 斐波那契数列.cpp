#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
//两矩阵乘法
vector<vector<long long> > MatrixPlus(vector<vector<long long> >& A, vector<vector<long long> >& B)
{
	vector<vector<long long> > res(A.size(),vector<long long>(B[0].size(),0));
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B[0].size(); j++)
		{
			for (int k = 0; k < B.size(); k++)
			{
				res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % mod;
			}
		}
	}
	return res;
}

//矩阵幂
vector<vector<long long> > MatrixMi(vector<vector<long long> >& A, long long p)
{
	vector<vector<long long> > res(A.size(),vector<long long>(A[0].size(),0));
	for (int i = 0; i < A.size(); i++)
	{
		res[i][i] = 1;
	}
	vector<vector<long long> > temp = A;
	for (; p; p >>= 1)
	{
		if ((p&1))
		{
			res = MatrixPlus(res,temp);
		}
		temp = MatrixPlus(temp,temp);
	}
	return res;
}

int f1(long long n)
{
	if (n < 1)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}
	vector<vector<long long> > base = {{1,1},{1,0}};
	vector<vector<long long> > res;
	res = MatrixMi(base,n-2);
	return (res[0][0]%mod + res[1][0]%mod) % mod;
}

int main()
{
	long long n;
	cin >> n;
	cout << f1(n);
	return 0;
}
