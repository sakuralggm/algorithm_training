/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 * 题目链接：https://leetcode.cn/problems/sliding-window-maximum
 * 是否独立完成：是
 * 提交次数：2
 * 时间复杂度：O(n)
 * 空间复杂度：O(k)
 * 题解：https://leetcode.cn/problems/sliding-window-maximum/solutions/543426/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m
 * 知识点：单调队列
 * 技巧：官方题解的第三种方法，分块+预处理前后缀数组值得学习
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (q.size() && i - q.front() + 1 > k) {
                q.pop_front();
            }
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

