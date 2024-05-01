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
 * 优化：
 * 参考题解：https://leetcode.cn/problems/minimum-window-substring/solutions/2713911/liang-chong-fang-fa-cong-o52mn-dao-omnfu-3ezz
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (auto i : t) {
            mt[i]++;
        }
        bool found = false;
        int l = 0, mins = 2e9;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            ms[s[i]]++;
            if (found == false) {
                bool cur = true;
                for (auto i : t) {
                    if (ms[i] < mt[i]) {
                        cur = false;
                        break;
                    }
                }
                if (cur == true) {
                    found = true;
                }
            }
            if (found) {
                while (!mt[s[l]] || ms[s[l]] - 1 >= mt[s[l]]) {
                    ms[s[l]]--;
                    l++;
                }
                if (i - l + 1 < mins) {
                    mins = i - l + 1;
                    ans = s.substr(l, i - l + 1);
                }
            }
        }
        if (found == false) {
            return string();
        } else {
            return ans;
        }
    }
};
// @lc code=end
