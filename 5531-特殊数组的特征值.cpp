/*
    LeetCode 5531
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for (int i = 0; i <= nums.size(); i++)
        {
            count = 0;

            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] >= i) count++;
            }
            
            if (count == i) return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {3,5};
    Solution A;
    cout << A.specialArray(nums) << endl;
    return 0;
}