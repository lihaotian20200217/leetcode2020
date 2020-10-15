/*
    笔试练习
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        int M/* 方格的边长*/, B/* 障碍物的个数*/, N/* 指令的个数*/;
        vector<vector<int>> block; //存放障碍物坐标
        int x, y, z;
        char c;
        vector<pair<char,int>> m;
        // 题目是一行一行的输入，所以我们也一行一行的输入
        cin >> M;
        cin >> B;
        cin >> N;
        // 循环输入障碍物坐标
        for (int i = 0; i < B; i++)
        {
            cin >> x >> y;
            block.push_back({x,y});
        }
        // 循环输入指令信息
        for (int i = 0; i < N; i++)
        {
            cin >> c >> z;
            m.push_back(make_pair(c,z));
        }
        // 这里用整形二维数组表示棋盘
        vector<vector<int>> arr(M,vector<int>(M,0));
        // 这里-1表示障碍
        for (int i = 0; i < B; i++)
        {
            arr[block[i][0]][block[i][1]] = -1;
        }
        int count = 0,/* 计数*/X = 0, Y = 0/* 模拟当前状态坐标*/;
        string flag = "***";
        for (int i = 0; i < N && flag != "INVALID"; i++)
        {
            if (m[i].first == 'R')
            {
                int sum = 0;
                for (int k = 0; k < m[i].second; k++)
                {
                    if (++Y >= M)
                    {
                        flag = "INVALID";
                        break;
                    }
                    else if (arr[X][Y] == -1)
                    {
                        count += m[i].second - sum;
                        arr[X][--Y] = count;
                        break;
                    }
                    else arr[X][Y] = ++count;
                    sum++;
                }
            }
            else if (m[i].first == 'L')
            {
                int sum = 0;
                for (int k = 0; k < m[i].second; k++)
                {
                    if (--Y < 0)
                    {
                        flag = "INVALID";
                        break;
                    }
                    else if (arr[X][Y] == -1)
                    {
                        count += m[i].second - sum;
                        arr[X][++Y] = count;
                        break;
                    }
                    else arr[X][Y] = ++count;
                    sum++;
                }
            }
            else if (m[i].first == 'D')
            {
                int sum = 0;
                for (int k = 0; k < m[i].second; k++)
                {
                    if (++X >= M)
                    {
                        flag = "INVALID";
                        break;
                    }
                    else if (arr[X][Y] == -1)
                    {
                        count += m[i].second - sum;
                        arr[--X][Y] = count;
                        break;
                    }
                    else arr[X][Y] = ++count;
                    sum++;
                }
            }
            else
            {
                int sum = 0;
                for (int k = 0; k < m[i].second; k++)
                {
                    if (--X < 0)
                    {
                        flag = "INVALID";
                        break;
                    }
                    else if (arr[X][Y] == -1)
                    {
                        count += m[i].second - sum;
                        arr[++X][Y] = count;
                        break;
                    }
                    else arr[X][Y] = ++count;
                    sum++;
                }
            }
        }
        if (flag == "INVALId") cout << flag;
        else
        {
            int i, j;
            for (i = 0; i < M; i++)
            {
                for (j = 0; j < M; j++)
                {
                    if (j == M-1)
                    {
                        if (arr[i][j] == -1) cout << "X";
                        else cout << to_string(arr[i][j]);
                    }
                    else
                    {
                        if (arr[i][j] == -1) cout << "X    ";
                        else
                        {
                            string ss = to_string(arr[i][j]);
                            cout << ss;
                            for (int k = 0; k < 5-ss.size(); k++) cout << " ";
                        }
                    }

                }
                cout << endl;
            }
        }
    }
    return 0;
}








