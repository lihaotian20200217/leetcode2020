/*
    LeetCode 1610
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> arr;
        double rad = 3.1415926 * angle / 180;
        int count = 0, sum = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int dx = points[i][0] - location[0];
            int dy = points[i][1] - location[1];
            if (dx == 0 && dy == 0) {count++; continue;}
            double ang = atan2(dy,dx);
            if (ang < 0) ang += 2 * 3.1415926;
            if (ang < rad) arr.push_back(ang + 2 * 3.1415926);
            arr.push_back(ang);
        }
        
        sort(arr.begin(),arr.end());
        int i = 0, j = 0;
        while (j < arr.size())
        {
            if ((arr[j] - arr[i]) < rad || abs(arr[j] - arr[i] - rad) < 0.0000001)
            {
                sum = max(sum,j-i+1);
                j++;
            }
            else i++;
        }
        //cout << sum;
        return count + sum;
    }
};

int main()
{
    vector<vector<int>> points = {{2,1},{2,2},{3,3}};
    int angle = 90;
    vector<int> location = {1,1};
    Solution A;
    cout << A.visiblePoints(points,angle,location) << endl;
    return 0;
}