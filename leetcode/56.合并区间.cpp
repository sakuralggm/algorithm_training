/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 * 题目链接：https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-100-liked
 * 本题耗时：5min
 * 提交次数：1
 * 是否独立完成：是
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(logn) 排序需要的空间
 * 知识点：合并区间模板题
 * 解题思路：将所有区间按照左端点排序，维护一个答案区间，遍历区间，当遍历到的区间的左端点超过当前答案区间的右端点时，说明遇到了
 * 一个不能合并到当前答案区间的新区间，保存答案区间，然后把答案区间更新为新的区间
 * 技巧：无
 * 优化：五
 * 错误：无
 * 参考题解：
 * 同类题目：
 * 初始写法：https://leetcode.cn/problems/merge-intervals/submissions/528719619?envType=study-plan-v2&envId=top-100-liked
 * 优化写法：
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int st = -1, ed = -1;
        for (auto seg : intervals) {
            int l = seg[0], r = seg[1];
            if (l > ed) {
                if (st != -1) {
                    ans.push_back({st, ed});
                }
                st = l;
                ed = r;
            } else {
                ed = max(ed, r);
            }
        }
        if (st != -1) {
            ans.push_back({st, ed});
        }
        return ans;
    }
};
// @lc code=end

