/*
	LeetCode 1631
	给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子 (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。

请你返回从左上角走到右下角的最小 体力消耗值 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <bits/stdc++.h>
uisng namespace std;

int idx[4] = {-1,1,0,0}, idy[4] = {0,0,-1,1};

bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& visit, int x, int y, int row, int col, int mid)
{
	if (x == row-1 && y == col-1) return true;
	visit[x][y] = true;
	int i, j;
	for (int k = 0; k < 4; k++)
	{
		i = idx[k] + x;
		j = idy[k] + y;
		if (i>=0&&i<row&&j>=0&&j<col&&!visit[i][j]&&abs(heights[i][j]-heights[x][y])<=mid)
		{
			if (dfs(heights,visit,i,j,row,col,mid) return true;
		}
	}
	return false;
}

int main()
{
	int row, col;
	cin >> row >> col;
	vector<vector<int>> heights(row,vector<int>(col,0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> heights[i][j];
		}
	}
	

	int row = heights.size(), col = heights[0].size();
	int left = 0, right = INT_MAX;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		vector<vector<bool>> visit(row,vector<bool>(col,false));
		if (dfs(height,visit,0,0,row,col,mid))
		{
			right = mid;
		}
		else left = mid + 1;
	}
	
	cout << right << endl;
	return 0;
}








