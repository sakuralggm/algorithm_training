/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 * 题目链接：https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked
 * 本题耗时：40min
 * 提交次数：4
 * 是否独立完成：否
 * 参考题解：https://leetcode.cn/problems/subarray-sum-equals-k/solutions/238572/he-wei-kde-zi-shu-zu-by-leetcode-solution
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 * 知识点：前缀和，数学技巧
 * 解题思路：很容易想到枚举右端点，然后对于每个右端点枚举所有左端点的做法，这个方法是0(n^2)的。而通过前缀和可以将复杂度减小一个n，具体看技巧
 * 
 * 技巧：如何判断以i结尾的子数组中是否有和为k的子数组
 * 如果有，则有前缀和pre[i] - pre[j - 1] == k
 * 则有pre[j - 1] == pre[i] - k, 0 <= j <= i
 * 也就是说，以i结尾的子数组中和为k的子数组的个数等于i前面的前缀和数组中值为pre[i]-k的元素的个数。这个用哈希表边遍历边记录即可
 * 注意：初始化hashMap[0] = 1，表示pre[-1] = 0
 * 
 * 用到类似技巧（记录前缀）的题目：https://www.acwing.com/problem/content/description/104/
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            ans += hashMap[pre - k];
            hashMap[pre]++;
        }
        return ans;
    }
};
// @lc code=end
