/*
    LeetCode 5532
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int flag = 1;//vector<vector<int>> arr;
        queue<TreeNode*> Q;
        Q.push(root);
        while (Q.size())
        {
            int len = Q.size();
            vector<int> h;
            for (int i = 0; i < len; i++)
            {
                TreeNode* ptr = Q.front();
                Q.pop();
                h.push_back(ptr->val);
                if (ptr->left) Q.push(ptr->left);
                if (ptr->right) Q.push(ptr->right);
            }
            //arr.push_back(h);
            if (flag == 1)
            {
                for (int j = 0; j < h.size(); j++)
                {
                    if (h[j]%2 == 0 || (j>0 && h[j] <= h[j-1])) return false;
                }
            }
            else
            {
                for (int j = 0; j < h.size(); j++)
                {
                    if (h[j]%2 || (j>0 && h[j] >= h[j-1])) return false;
                }
            }
            flag = -flag;
        }
        /*for (int i = 0; i < arr.size(); i++)
        {
            if (i%2 == 0)
            {
                for (int j = 0; j < arr[i].size(); j++)
                {
                    if (arr[i][j]%2 == 0 || (j>0 && arr[i][j] <= arr[i][j-1])) return false;
                }
            }
            else
            {
                for (int j = 0; j < arr[i].size(); j++)
                {
                    if (arr[i][j]%2 || (j>0 && arr[i][j] >= arr[i][j-1])) return false;
                }
            }
        }*/
        return true;
    }
};

int main()
{
    // 构建测试用例
    TreeNode* r1 = new TreeNode(5);
    TreeNode* r2 = new TreeNode(4);
    TreeNode* r3 = new TreeNode(2);
    TreeNode* r4 = new TreeNode(3);
    TreeNode* r5 = new TreeNode(3);
    TreeNode* r6 = new TreeNode(7);
    r1->left = r2, r1->right = r3, r2->left = r4, r2->right = r5, r3->left = r6;
    Solution A;
    cout << A.isEvenOddTree(r1) << endl;
    return 0;
}