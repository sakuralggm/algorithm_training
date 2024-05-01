/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 题目链接：https://leetcode.cn/problems/minimum-window-substring
 * 本题耗时：40min
 * 提交次数：4
 * 是否独立完成：是
 * 时间复杂度：O(52*slen + tlen)
 * 空间复杂度：O(52)
 * 知识点：滑动窗口，左右指针
 * 解题思路：初始化左右指针为0，右指针右移，找到第一个覆盖的子串，然后左指针右移收缩窗口（字符不在t里或者删去之后仍然覆盖）。之后右指针右移，新增字符，左指针右移收缩窗口，保持窗口始终覆盖，找到所有以i为右端点满足条件的最短子串，更新答案。
 * 优化：用一个变量differ维护目前子串中有differ种字母的出现次数小于t中字母的出现次数。每次指针移动时更新differ，当differ==0时，满足条件。这是借用了快速比较两个数组是否相等的优化方法：https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1123971/zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-xzin
 * 参考题解：https://leetcode.cn/problems/minimum-window-substring/solutions/2713911/liang-chong-fang-fa-cong-o52mn-dao-omnfu-3ezz
 * 初始写法：https://leetcode.cn/problems/minimum-window-substring/submissions/528481185
 * 优化写法：https://leetcode.cn/problems/minimum-window-substring/submissions/528539956
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;
        int differ = 0, left = 0;
        int ans_l = -1, ans_r = 2e9;
        string ans;
        for (auto i : t) {
            mt[i]++;
        }
        differ = mt.size();
        for (int i = 0; i < s.size(); i++) {
            if (mt[s[i]] && ms[s[i]] == mt[s[i]] - 1) {
                differ--;
            }
            ms[s[i]]++;
            while (differ == 0) {
                if (i - left + 1 < ans_r - ans_l + 1) {
                    ans_l = left;
                    ans_r = i;
                }
                if (mt[s[left]] && ms[s[left]] == mt[s[left]]) {
                    differ++;
                }
                ms[s[left]]--;
                left++;
            }
        }
        if (ans_l != -1) {
            return s.substr(ans_l, ans_r - ans_l + 1);
        } else {
            return string();
        }
    }
};
// @lc code=end
