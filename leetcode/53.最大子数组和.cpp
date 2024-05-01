/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * 题目链接：https://leetcode.cn/problems/maximum-subarray
 * 本题耗时：5min
 * 提交次数：1
 * 是否独立完成：是
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 知识点：线性DP
 * 解题思路：dp[i]记录以i结尾的子数组的最大和，对于第i个数，如果dp[i-1]大于0，则加入它，dp[i]=dp[i-1]+nums[i]，否则自己另起一个子数组，dp[i]=nums[i]
 * 技巧：使用滚动数组优化空间复杂度
 * 优化：每次的dp[i]的计算只用到dp[i-1]，我们可以用一个pre来记录即可，并且每次更新pre后就更新一下答案，空间复杂度变为O(1)
 * 错误：一开始没看出来是线性DP，看了一眼思路才知道自己做过，说明我没有把握线性DP的切入点。可以这样想，已经有了一个子数组，对于一个新的元素，应该怎么办。
 * 参考题解：https://leetcode.cn/problems/maximum-subarray/solutions/228009/zui-da-zi-xu-he-by-leetcode-solution
 * 初始写法：https://leetcode.cn/problems/maximum-subarray/submissions/528544367?envType=study-plan-v2&envId=top-100-liked
 * 优化写法：https://leetcode.cn/problems/maximum-subarray/submissions/528545111?envType=study-plan-v2&envId=top-100-liked
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], pre = nums[0];
        for (int i = 1; i < n; i ++) {
            if (pre > 0) {
                pre += nums[i];
            } else {
                pre = nums[i];
            }
            ans = max(ans, pre);
        }
        return ans;
    }
};
// @lc code=end

