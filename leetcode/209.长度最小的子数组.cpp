/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 * 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum
 * 本题耗时：10min
 * 提交次数：3
 * 是否独立完成：是
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 * 知识点：滑动窗口，左右指针
 * 解题思路：维护一个滑动窗口（左右指针），注意到nums数组中都是正数，因此右指针右移一定会使窗口内的和增大，左指针右移一定会使窗口内的值减小。那么，我们可以初始化左右指针相同，都为0，然后右指针右移，增大区间和，当区间内的和大于等于target时，左指针收缩窗口，得到一个可行解，更新ans。之后右指针继续右移，寻找下一个可行解。用这种方法一定可以找到所有的，以i为右端点，且和大于等于target的最短区间。
 * 技巧：左右指针的移动给目标值的影响是固定（不满足->满足或者满足->不满足）的，称之为单调性，这是我们可以用左右指针维护滑动窗口的条件
 * 错误：一开始看成要等于target，没有判断解不存在时的输出。
 * 讲解：https://www.bilibili.com/video/BV1hd4y1r7Gq
 * 同类题目：https://leetcode.cn/problems/minimum-window-substring，这道题也具有单调性
 * 拓展：如果数组元素含有负数，怎么做？（1）枚举右端点，向左拓展找最短区间的O(n^2)暴力做法
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 2e9;
        int sum = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (1) {
                if (sum - nums[left] < target) {
                    break;
                } else {
                    sum -= nums[left];
                    left++;
                }
            }
            if (sum >= target) {
                ans = min(ans, i - left + 1); 
            }
        }
        return sum >= target ? ans : 0;
    }
};
// @lc code=end
