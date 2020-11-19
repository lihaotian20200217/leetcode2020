/*
	给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

进阶：

你能在线性时间复杂度内解决此题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7]
解释:

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums,int k)
		{
			vector<int> res;
			deque<int> que;
			if (nums.size() == 0) return res;
			for (int i = 0; i < k; i++)
			{
				while (!que.empty() && nums[i] > nums[que.back()]) que.pop_back();
				que.push_back(i);
			}
			res.push_back(nums[que.front()]);
			for (int i = k; i < nums.size(); i++)
			{
				while (!que.empty() && nums[i] > nums[que.back()]) que.pop_back();
				while (!que.empty() && que.front() <= i-k) que.pop_front();
				que.push_back(i);
				res.push_back(nums[que.front()]);
			}
			return res;
		}
};

int main()
{
	Solution A;
	vector<int> arr = {1,3,-1,-3,5,3,6,7};
	arr = A.maxSlidingWindow(arr,3);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}	


/*
	补充：
	deque容器为一个给定类型的元素进行线性处理，像向量一样，它能够快速地随机访问
	任一个元素，并且能够高效地插入和删除容器的尾部元素。但它与vector不同，deque
	支持高效地插入和删除容器的头部元素，因此也叫做双端队列。
	1.构造函数
		deque();
		deque(int nSize);
		deque(int nSize, const T& t);
		deque(const deque &);
	2.增加函数
		void push_front(const T& x);
		void push_back(const T& x);
		iterator insert(iterator it, const T& x);
		void insert(iterator it, int n, const T& x);
		void insert(iterator it, const_iterator first, const_iterator last);
	3.删除函数
		iterator erase(iterator it);
		iterator erase(iterator first, iterator last);
		void pop_front();
		void pop_back();
		void clear();
	4.遍历函数
		reference at(int pos);
		reference front();
		reference back();
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
	5.判断函数
		bool empty() const;
	6.大小函数
		int size() const;
		int max_size() const;
*/

















