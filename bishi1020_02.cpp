/*
	小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。小Q从第一栋一直走到了最后一栋，小Q从来都没有见过这么多楼，所以他想知道在每栋楼的位置处能看到多少栋楼？（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住）
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
stack<int> st1, st2;

int main()
{
	int n, x[100001];
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> x[i];

	for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
	{
		a.push_back(st1.size());
		b.push_back(st2.size());

		while (!st1.empty() && st1.top() <= x[i]) st1.pop();
		while (!st2.empty() && st2.top() <= x[j]) st2.pop();
		st1.push(x[i]);
		st2.push(x[j]);
	}
	reverse(b.begin(),b.end());
	for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1 << " ";
	return 0;
}
