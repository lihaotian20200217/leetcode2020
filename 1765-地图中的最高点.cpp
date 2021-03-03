class Solution {
    public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int m = isWater.size(), n = isWater[0].size();
		int idx[4] = {-1,1,0,0}, idy[4] = {0,0,-1,1};
		vector<vector<int>> res(m,vector<int>(n,0));
		vector<vector<int>> vis(m,vector<int>(n,0));
		queue<pair<int,int>> que;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (isWater[i][j] == 1)
				{
					que.push(make_pair(i,j));
					vis[i][j] = 1;
				}
			}
		}
		while (!que.empty())
		{
			int x = que.front().first;
			int y = que.front().second;
			que.pop();
			for (int i = 0; i < 4; i++)
			{
				if (x+idx[i] >= 0 &&
						x+idx[i] < m && y+idy[i] >= 0 && y+idy[i] < n &&
						vis[x+idx[i]][y+idy[i]] != 1)
				{
					res[x+idx[i]][y+idy[i]] = res[x][y] + 1;
					vis[x+idx[i]][y+idy[i]] = 1;
					que.push(make_pair(x+idx[i],y+idy[i]));
				}
			}
		}
		return res;
	}
};
